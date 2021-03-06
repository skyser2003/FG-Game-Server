process.chdir(__dirname);

var fs = require('fs');
var execSync = require('child_process').execSync;
var spawnSync = require('child_process').spawnSync;
var os = require('os');
var path = require('path');

var helper = require('./helper');

var args = process.argv.slice(2);
var searchDirs = args[0].split(';');
var inputDirs = args[1].split(';');
var outputDir = args[2];

// Generate cpp & csharp files from .proto files
try {
    fs.statSync(outputDir);
}
catch (err) {
    fs.mkdirSync(outputDir);
}

var protoc = '';

if (os.platform() == 'win32') {
    protoc = path.resolve(String.raw`..\protoc\protoc`);
} else {
    protoc = 'protoc';
}

var subDirs = [];

for (var inputDir of inputDirs) {
    var dirs = helper.getAllDirsContainingExtension(inputDir, 'proto');

    for (var dir of dirs) {
        subDirs.push(path.resolve(dir, '*.proto'));
    }
}

var cppOutArgs = searchDirs.map(searchDir => { return '--proto_path=' + path.resolve(searchDir); }).concat([
    '--cpp_out=' + outputDir
]).concat(subDirs);

var cppOut = spawnSync(protoc, cppOutArgs);
helper.printSpawnLog('Cpp', cppOut);

console.log('protobuf source build done');