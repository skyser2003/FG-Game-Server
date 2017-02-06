process.chdir(__dirname);

var fs = require('fs');
var spawnSync = require('child_process').spawnSync;
var args = process.argv.slice(2);

var searchDir = args[0];
var protoDir = args[1];
var outputDir = args[2];

var buildProtoArgs = [
    'build_proto',
    searchDir,
    protoDir,
    outputDir
];

var generatePacketInfoArgs = [
    'generate_packet_info',
    protoDir,
    outputDir
];

var buildProto = spawnSync('node', buildProtoArgs);
var generatePacketInfo = spawnSync('node', generatePacketInfoArgs);

console.log(buildProto.stdout.toString());
console.log(buildProto.stderr.toString());

console.log(generatePacketInfo.stdout.toString());
console.log(generatePacketInfo.stderr.toString());