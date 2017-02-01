process.chdir(__dirname);

var fs = require('fs');
var path = require('path');
var execSync = require('child_process').execSync;

var helper = require('./helper');

var args = process.argv.slice(2);
var inputDirs = args[0].split(';').map(dir => { return path.resolve(dir); });
var outputDir = args[1];

// Init npm if not already init
try {
    fs.statSync('node_modules');
}
catch (err) {
    execSync('npm install');
}

var protobuf = require('protobufjs');
var ejs = require('ejs');

try {
    fs.statSync('../Autogen')
}
catch (err) {
    fs.mkdirSync('../Autogen');
}

var headerList = [];
var buildList = [];

var protoFilesPerDir = inputDirs.map(inputDir => { return helper.getAllFilesWithExtension(inputDir, 'proto'); });

for (var i = 0; i < inputDirs.length; ++i) {
    var inputDir = inputDirs[i];
    var protoFiles = protoFilesPerDir[i];

    for (var file of protoFiles) {
        var loaded = protobuf.loadSync(file);

        var headerName = path.basename(file);
        headerName = headerName.replace(path.extname(headerName), '');
        headerName += '.pb';

        headerList.push(path.basename(headerName));
        buildList.push(loaded);

        continue;

        var builder = protobuf.loadProtoFile({
            root: inputDir,
            file: file
        });

        headerList.push(path.basename(file));
        buildList.push(builder.build());
    }
}

var enumList = {};
var structList = {};

// Distinguish out enum and struct proto files
for (var build of buildList) {
    var enumRoot = build.PKENUM;
    if (enumRoot === undefined) {
        continue;
    }

    for (var enumTypeName in enumRoot) {
        var regex = new RegExp(/^(.*)PacketEnum$/);
        var match = enumTypeName.match(regex);

        if (match === null) {
            continue;
        }

        var namespace = match[1];
        enumList[namespace] = {};

        for (var enumName in enumRoot[enumTypeName]) {
            var prefix = namespace + '_';
            if (enumName.indexOf(prefix) != 0) {
                continue;
            }

            var enumTrueName = enumName.replace(prefix, '');
            enumList[namespace][enumTrueName] = enumRoot[enumTypeName][enumName];
        }
    }
}

for (var build of buildList) {
    var structRoot = build.PKS;
    if (structRoot === undefined) {
        continue;
    }

    for (var namespace in enumList) {
        var prefix = namespace + '_';
        for (var structName in structRoot) {
            if (structName.indexOf(prefix) != 0) {
                continue;
            }

            var structTrueName = structName.replace(prefix, '');
            if (enumList[namespace][structTrueName] === undefined) {
                continue;
            }

            if (structList[namespace] === undefined) {
                structList[namespace] = [];
            }

            structList[namespace].push(structTrueName);
        }
    }
}

var list = [];

// Final data struct for ejs template
for (var namespace in structList) {
    for (var i in structList[namespace]) {
        var trueName = structList[namespace][i];
        var enumNamespaceList = enumList[namespace];

        var enumType = 'PKENUM::' + namespace + 'PacketEnum';
        var enumName = enumType + '::' + namespace + '_' + trueName;
        var structName = 'PKS::' + namespace + '_' + trueName;

        var ejsStruct = {
            pksName: structName,
            enumType: enumType,
            enumName: enumName
        };

        list.push(ejsStruct);
    }
}

ejs.renderFile('PksInfo.ejs', { list: list, headerList: headerList }, function (err, str) {
    fs.writeFile(path.resolve(outputDir, 'PksInfo.h'), str);
    console.log('PksInfo.h generate done');
});

ejs.renderFile('PkEnumInfo.ejs', { list: list, headerList: headerList }, function (err, str) {
    fs.writeFile(path.resolve(outputDir, 'PkEnumInfo.h'), str);
    console.log('PkEnumInfo.h generate done');
});