process.chdir(__dirname);

var fs = require('fs');
var execSync = require('child_process').execSync;
var spawnSync = require('child_process').spawnSync;
var os = require('os');
var path = require('path');

var helper = require('./helper');

var args = process.argv.slice(2);
var inputDirs = args[0].split(';');
var outputDir = args[1];
var csharpDir = args[2];

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

var cppOutArgs = inputDirs.map(inputDir => { return '--proto_path=' + path.resolve(inputDir); }).concat([
    '--cpp_out=' + outputDir,
    '--descriptor_set_out=' + path.resolve(outputDir, 'proto.protobin')
]).concat(subDirs);

var cppOut = spawnSync(protoc, cppOutArgs);
helper.printSpawnLog('Cpp', cppOut);

if (csharpDir !== undefined) {
    console.log(csharpDir);
    try {
        fs.statSync(csharpDir);
    }
    catch (err) {
        fs.mkdirSync(csharpDir);
    }

    var csharpOutput = spawnSync(String.raw`..\protoc\ProtoGen`,
        [
            String.raw`-o:..\..\..\Client\Assets\Script\PacketMsg\PacketProtobuf.cs`,
            String.raw`-i:..\src_proto\proto.protobin`
        ]);

    helper.printSpawnLog('CSharp', csharpOutput);
}

console.log('protobuf source build done');
