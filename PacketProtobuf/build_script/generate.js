process.chdir(__dirname);

var fs = require('fs');
var spawnSync = require('child_process').spawnSync;
var args = process.argv.slice(2);

var protoDir = args[0];
var srcDir = args[1];
var infoHeaderDir = args[2];
var csharpDir = args[3];

var buildProtoArgs = [
    'build_proto',
    protoDir,
    srcDir
];

if (csharpDir !== undefined) {
    buildProtoArgs.push(csharpDir);
}

var generatePacketInfoArgs = [
    'generate_packet_info',
    infoHeaderDir
];

var buildProto = spawnSync('node', buildProtoArgs);
var generatePacketInfo = spawnSync('node', generatePacketInfoArgs);

console.log(buildProto.stdout.toString());
console.log(buildProto.stderr.toString());

console.log(generatePacketInfo.stdout.toString());
console.log(generatePacketInfo.stderr.toString());