module("Vector2D test");

test ("Equals", function() {
    var a = new C.Geometry.Vector2(5, 8);
    var b = new C.Geometry.Vector2(42, 10);
    ok (! (a.Equals(b)), "Vector shouldn't be equals");
    ok (a.Equals(a), "Vector should be equals");
});

test ("Distance", function () {
    var a = new C.Geometry.Vector2(5, 8);
    var b = new C.Geometry.Vector2(42, 10);
    var distance = a.Distance(b);
    ok (C.Utils.Comparison.Equals(distance, 37.054014627297809172542799375637), "Distance is wrong");
});

test ("DotProduct", function () {
    var a = new C.Geometry.Vector2(5, 8);
    var b = new C.Geometry.Vector2(42, 10);
    var dot = a.DotProduct(b);
    ok (C.Utils.Comparison.Equals(dot, 290), "DotProduct is wrong");
});

module("Vector3D test");

test ("Equals", function() {
    var a = new C.Geometry.Vector3(5, 8, 9);
    var b = new C.Geometry.Vector3(42, 10, 30);
    ok (! (a.Equals(b)), "Vector shouldn't be equals");
    ok (a.Equals(a), "Vector should be equals");
});

test ("Distance", function () {
    var a = new C.Geometry.Vector3(5, 8, 9);
    var b = new C.Geometry.Vector3(42, 10, 30);
    var distance = a.Distance(b);
    ok (C.Utils.Comparison.Equals(distance, 42.591078878093708134734694132318), "Distance is wrong");
});

test ("DotProduct", function () {
    var a = new C.Geometry.Vector3(5, 8, 9);
    var b = new C.Geometry.Vector3(42, 10, 30);
    var dot = a.DotProduct(b);
    ok (C.Utils.Comparison.Equals(dot, 560), "DotProduct is wrong");
});
