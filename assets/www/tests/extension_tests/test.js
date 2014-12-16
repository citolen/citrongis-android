
var fileInput = document.getElementById('file');
var fileInput1 = document.getElementById('file1');

function fileChanged() {
    var reader = new FileReader();

    reader.onload = function() {
        var extZip = new JSZip();
        extZip.load(reader.result);

        var e = new C.Extension.Extension(extZip);
        C.Extension.Manager.register(e);
        debugPackage(e.package);

        e.module.ui.on('display', function (element) {
            document.body.appendChild(element);
        });

        e.run();

        console.log(e.module.exports);
    };

    reader.readAsArrayBuffer(this.files[0]);
};

fileInput.onchange = fileChanged;
fileInput1.onchange = fileChanged;


function debugPackage(package) {
    console.log("name:" + package.name);
    console.log("version:" + package.version);
    console.log("main:" + package.main);
}
