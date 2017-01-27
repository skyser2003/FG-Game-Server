process.chdir(__dirname);

var fs = require('fs');
var execSync = require('child_process').execSync;
var spawnSync = require('child_process').spawnSync;
var os = require('os');
var path = require('path');

var helper = require('./helper');

var args = process.argv.slice(2);
var inputDir = args[0];
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
    protoc = String.raw`..\protoc\protoc`;
} else {
    protoc = 'protoc';
}

var realSubDirs = [];

var subDirs = helper.getAllDirsContainingExtension(inputDir, 'proto');
for (var i = 0; i < subDirs.length; ++i) {
    subDirs[i] = path.resolve(subDirs[i], '*.proto');
}

var cppOut = spawnSync(protoc,
    [
        '--proto_path=' + inputDir,
        '--cpp_out=' + outputDir,
        '--descriptor_set_out=' + outputDir + '/proto.protobin',
    ].concat(subDirs)
);

printLog('Cpp', cppOut);

if (csharpDir !== undefined) {
    console.log(csharpDir);
    try {
        fs.statSync(csharpDir);
    }
    catch (err) {
        fs.mkdirSync(csharpDir);
    }

    var csharpOutput = spawnSync('../protoc/ProtoGen',
        [
            String.raw`-o:..\..\..\Client\Assets\Script\PacketMsg\PacketProtobuf.cs`,
            String.raw`-i:..\src_proto\proto.protobin`
        ]);

    printLog('CSharp', csharpOutput);
}

console.log('protobuf source build done');

function printLog(prefix, spawn) {
    var stdout = spawn.stdout;
    var stderr = spawn.stdout;

    var stdoutStr = stdout.length == 0 ? 'no stdout' : stdout.toString();
    var stderrStr = stderr.length == 0 ? 'no stderr' : stderr.toString();

    console.log(prefix + ' stdout: ' + stdoutStr);
    console.log(prefix + ' stderr: ' + stderrStr);
}