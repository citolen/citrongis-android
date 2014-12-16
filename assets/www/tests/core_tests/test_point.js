console.log("Proj4 version:" + proj4.version);

var projRDNew = new proj4.Proj('PROJCS["Amersfoort / RD New", GEOGCS["Amersfoort", DATUM["Amersfoort", SPHEROID["Bessel 1841",6377397.155,299.1528128, AUTHORITY["EPSG","7004"]], AUTHORITY["EPSG","6289"]], PRIMEM["Greenwich",0, AUTHORITY["EPSG","8901"]], UNIT["degree",0.01745329251994328, AUTHORITY["EPSG","9122"]], AUTHORITY["EPSG","4289"]], UNIT["metre",1, AUTHORITY["EPSG","9001"]], PROJECTION["Oblique_Stereographic"], PARAMETER["latitude_of_origin",52.15616055555555], PARAMETER["central_meridian",5.38763888888889], PARAMETER["scale_factor",0.9999079], PARAMETER["false_easting",155000], PARAMETER["false_northing",463000], AUTHORITY["EPSG","28992"], AXIS["X",EAST], AXIS["Y",NORTH]]');
var p = new C.Geometry.Point(4.913029, 52.342404, 0, proj4.WGS84);

module("Point Reprojection");
test("100000 reprojections", function() {
    var pInRDNew;
    for (var i = 0; i < 100000; i++) {
        pInRDNew = C.Helpers.CoordinatesHelper.TransformTo(p, projRDNew);
    }
    ok(true, 'success, check execution time');
});
