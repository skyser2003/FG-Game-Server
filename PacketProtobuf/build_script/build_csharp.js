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
var csharpFile = args[3];

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

var csharpDir = path.dirname(csharpFile);
try {
    fs.statSync(csharpDir);
}
catch (err) {
    fs.mkdirSync(csharpDir);
}

var protobin = path.resolve(outputDir, 'proto.protobin');

var protobinArgs = searchDirs.map(searchDir => { return '--proto_path=' + path.resolve(searchDir); }).concat([
    '--descriptor_set_out=' + protobin
]).concat(subDirs);

var protobinOutput = spawnSync(protoc, protobinArgs);
helper.printSpawnLog('Protobin', protobinOutput);

var csharpOutput = spawnSync(String.raw`..\protoc\ProtoGen`, [
    '-o:' + path.resolve(csharpFile),
    '-i:' + protobin
]);

helper.printSpawnLog('CSharp', csharpOutput);

fs.unlinkSync(protobin);

console.log('protobuf source build done');