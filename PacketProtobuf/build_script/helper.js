var fs = require('fs');
var path = require('path');

var getAllFiles = function (dir) {
    var ret = [];

    var dirs = getAllDirs(dir);

    for (var dir of dirs) {
        var files = fs.readdirSync(dir);

        for (var file of files) {
            file = path.resolve(dir, file);

            if (fs.statSync(file).isDirectory() === false) {
                ret.push(file);
            }
        }
    }

    return ret;
};

var getAllDirsContainingExtension = function (dir, ext) {
    var ret = [];

    var dirs = getAllDirs(dir);

    for (var dir of dirs) {
        var files = fs.readdirSync(dir);

        for (var file of files) {
            file = path.resolve(dir, file);
            var stat = fs.statSync(file);

            if (stat.isDirectory() === false && path.extname(file) === '.' + ext) {
                ret.push(dir);
                break;
            }
        }
    }

    return ret;
};

var getAllDirs = function (dir) {
    var ret = [path.resolve(dir)];

    var files = fs.readdirSync(dir);

    for (var i = 0; i < files.length; ++i) {
        var file = path.resolve(dir, files[i]);

        if (fs.statSync(file).isDirectory() === true) {
            ret = ret.concat(getAllDirs(file));
        }
    };

    return ret;
};

module.exports.getAllFiles = getAllFiles;
module.exports.getAllDirsContainingExtension = getAllDirsContainingExtension;
module.exports.getAllDirs = getAllDirs;