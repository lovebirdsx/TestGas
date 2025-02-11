"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const gulp = require("gulp");
const path = require("path");
const gulp_util_1 = require("gulp-util");
require("./packages/testGas");
const util_1 = require("./common/util");
const config_1 = require("./config");
const exec_1 = require("./common/exec");
const workingDir = path.resolve(__dirname, '../..');
gulp.task('clean', (cb) => {
    (0, gulp_util_1.log)(`Cleaning pwd: ${workingDir}`);
    (0, util_1.cleanDir)(path.join(workingDir, 'node_modules'));
    (0, util_1.cleanDir)(path.join(workingDir, 'tools', 'node_modules'));
    (0, util_1.cleanDir)(path.join(workingDir, 'Binaries'));
    (0, util_1.cleanDir)(path.join(workingDir, 'Intermediate'));
    (0, util_1.cleanDir)(path.join(workingDir, 'Saved'));
    (0, util_1.cleanDir)(path.join(workingDir, 'DerivedDataCache'));
    cb();
});
function init() {
    const config = (0, config_1.getConfig)();
    if (config.verbose) {
        (0, exec_1.setExecVerbose)(true);
    }
}
init();
//# sourceMappingURL=gulpfile.js.map