//
//
//  CitronGIS first app
//
//

var testContent = require('toto');

var MyApp = (function() {
    /* private member */
    var my_private_member = 1;

    /* private function */
    var my_private_function = function () {
        console.log('call my private func');
    }

    return ({
        /* public member */
        my_public_member: 5,

        /* public function */
        my_public_function: function () {
            console.log('call my public function');
            my_private_function();
        }
    });
})();

MyApp.my_public_function();

console.log(C);

var p = new C.Geometry.Point(51, 4.3, 0, C.Helpers.ProjectionsHelper.WGS84);
console.log(p);
console.log(p.TransformTo(C.Helpers.ProjectionsHelper.EPSG3857));

console.log(module);


module.ui.display('html/view/index.tmpl');

module.exports = {
    toto: function () {
        console.log(p);
    }
};
