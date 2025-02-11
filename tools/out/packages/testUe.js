"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const gulp = require("gulp");
const path = require("path");
const fs = require("fs");
const unrealTool_1 = require("../common/unrealTool");
const util_1 = require("../common/util");
const workingDir = path.resolve(__dirname, '../../..');
const uproject = path.join(workingDir, 'TestUe.uproject');
async function build() {
    await (0, unrealTool_1.execUnrealTool)({
        type: 'build',
        args: ['TestUeEditor', 'Win64', 'Development', `-Project="${uproject}"`, '-WaitMutex', '-FromMSBuild'],
        logPrefix: '[build] ',
        workingDir,
    });
}
async function runEditor() {
    const uproject = path.join(workingDir, 'TestUe.uproject');
    await (0, unrealTool_1.execUnrealTool)({
        type: 'unrealEditor',
        args: [`"${uproject}"`],
        logPrefix: '[editor] ',
        workingDir,
    });
}
async function runEditorTest() {
    await (0, unrealTool_1.execUnrealTool)({
        type: 'unrealEditor',
        args: [`"${uproject}"`, '-execcmds="Automation RunTests StartsWith:TestUe.; Quit"', '-unattended', '-stdout', '-nopause', '-nosound', '-NOSPLASH', '-NullRHI'],
        logPrefix: '[test] ',
        workingDir,
    });
}
async function runClean() {
    (0, util_1.cleanDir)(path.join(workingDir, 'Binaries'));
    (0, util_1.cleanDir)(path.join(workingDir, 'Intermediate'));
    (0, util_1.cleanDir)(path.join(workingDir, 'Saved'));
    (0, util_1.cleanDir)(path.join(workingDir, 'DerivedDataCache'));
    const pluginsDir = path.join(workingDir, 'Plugins');
    if (fs.existsSync(pluginsDir)) {
        fs.readdirSync(pluginsDir).forEach((plugin) => {
            (0, util_1.cleanDir)(path.join(pluginsDir, plugin, 'Binaries'));
            (0, util_1.cleanDir)(path.join(pluginsDir, plugin, 'Intermediate'));
            (0, util_1.cleanDir)(path.join(pluginsDir, plugin, 'Saved'));
            (0, util_1.cleanDir)(path.join(pluginsDir, plugin, 'DerivedDataCache'));
        });
    }
}
gulp.task('build', build);
gulp.task('editor', runEditor);
gulp.task('editor:watch', async () => {
    await build();
    await runEditor();
    const watchDirGlob = path.join(workingDir, 'Source', 'TestUe') + '/**/*';
    gulp.watch(watchDirGlob, gulp.series('build', 'editor'));
});
gulp.task('editor-test', async () => {
    await build();
    await runEditorTest();
});
gulp.task('editor-test:watch', async () => {
    await build();
    await runEditorTest();
    const watchDirGlob = path.join(workingDir, 'Source', 'TestUe') + '/**/*';
    gulp.watch(watchDirGlob, gulp.series('editor-test'));
});
gulp.task('clean', runClean);
gulp.task('runuat-help', async () => {
    await (0, unrealTool_1.execUnrealTool)({
        type: 'runuat',
        args: ['-Help'],
        logPrefix: '[runuat-help] ',
        workingDir,
        verbose: true,
    });
});
//# sourceMappingURL=testUe.js.map