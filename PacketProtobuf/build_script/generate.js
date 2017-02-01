process.chdir(__dirname);

var fs = require('fs');
var spawnSync = require('child_process').spawnSync;
var args = process.argv.slice(2);

var protoDir = args[0];
var srcDir = args[1];
var infoHeaderDir = args[2];
var csharpFile = args[3];

var buildProtoArgs = [
    'build_proto',
    protoDir,
    srcDir
];

if (csharpFile !== undefined) {
    buildProtoArgs.push(csharpFile);
}

var generatePacketInfoArgs = [
    'generate_packet_info',
    protoDir,
    infoHeaderDir
];

var buildProto = spawnSync('node', buildProtoArgs);
var generatePacketInfo = spawnSync('node', generatePacketInfoArgs);

console.log(buildProto.stdout.toString());
console.log(buildProto.stderr.toString());

console.log(generatePacketInfo.stdout.toString());
console.log(generatePacketInfo.stderr.toString());