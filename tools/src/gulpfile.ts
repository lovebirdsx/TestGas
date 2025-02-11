import * as gulp from 'gulp';
import * as path from 'path';
import { log } from 'gulp-util';

import './packages/testGas';

import { cleanDir } from './common/util';
import { getConfig } from './config';
import { setExecVerbose } from './common/exec';

const workingDir = path.resolve(__dirname, '../..');

gulp.task('clean', (cb: () => void): void => {
    log(`Cleaning pwd: ${workingDir}`);
    cleanDir(path.join(workingDir, 'node_modules'));
    cleanDir(path.join(workingDir, 'tools', 'node_modules'));
    cleanDir(path.join(workingDir, 'Binaries'));
    cleanDir(path.join(workingDir, 'Intermediate'));
    cleanDir(path.join(workingDir, 'Saved'));
    cleanDir(path.join(workingDir, 'DerivedDataCache'));

    cb();
});

function init() {
    const config = getConfig();
    if (config.verbose) {
        setExecVerbose(true);
    }
}

init();
