import * as gulp from 'gulp';
import * as path from 'path';
import * as fs from 'fs';

import { execUnrealTool } from '../common/unrealTool';
import { cleanDir } from '../common/util';

const workingDir = path.resolve(__dirname, '../../..');
const uproject = path.join(workingDir, 'TestGas.uproject');

async function build() {
    await execUnrealTool({
        type: 'build',
        args: ['TestGasEditor', 'Win64', 'Development', `-Project="${uproject}"`, '-WaitMutex', '-FromMSBuild'],
        logPrefix: '[build] ',
        workingDir,
    });
}

async function runEditor() {
    const uproject = path.join(workingDir, 'TestGas.uproject');
    await execUnrealTool({
        type: 'unrealEditor',
        args: [`"${uproject}"`],
        logPrefix: '[editor] ',
        workingDir,
    });
}

async function runEditorTest() {
    await execUnrealTool({
        type: 'unrealEditor',
        args: [`"${uproject}"`, '-execcmds="Automation RunTests StartsWith:TestGas.; Quit"', '-unattended', '-stdout', '-nopause', '-nosound', '-NOSPLASH', '-NullRHI'],
        logPrefix: '[test] ',
        workingDir,
    });
}

async function runClean() {
    cleanDir(path.join(workingDir, 'Binaries'));
    cleanDir(path.join(workingDir, 'Intermediate'));
    cleanDir(path.join(workingDir, 'Saved'));
    cleanDir(path.join(workingDir, 'DerivedDataCache'));

    const pluginsDir = path.join(workingDir, 'Plugins');
    if (fs.existsSync(pluginsDir)) {
        fs.readdirSync(pluginsDir).forEach((plugin) => {
            cleanDir(path.join(pluginsDir, plugin, 'Binaries'));
            cleanDir(path.join(pluginsDir, plugin, 'Intermediate'));
            cleanDir(path.join(pluginsDir, plugin, 'Saved'));
            cleanDir(path.join(pluginsDir, plugin, 'DerivedDataCache'));
        });
    }
}

gulp.task('build', build);

gulp.task('editor', runEditor);

gulp.task('editor:watch', async () => {
    await build();
    await runEditor();

    const watchDirGlob = path.join(workingDir, 'Source', 'TestGas') + '/**/*';
    gulp.watch(watchDirGlob, gulp.series('build', 'editor'));
});

gulp.task('editor-test', async () => {
    await build();
    await runEditorTest();
});

gulp.task('editor-test:watch', async () => {
    await build();
    await runEditorTest();

    const watchDirGlob = path.join(workingDir, 'Source', 'TestGas') + '/**/*';
    gulp.watch(watchDirGlob, gulp.series('editor-test'));
});

gulp.task('clean', runClean);

gulp.task('runuat-help', async () => {
    await execUnrealTool({
        type: 'runuat',
        args: ['-Help'],
        logPrefix: '[runuat-help] ',
        workingDir,
        verbose: true,
    });
});
