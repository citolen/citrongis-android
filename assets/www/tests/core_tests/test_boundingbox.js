module("BoundingBox");

var a = new C.Geometry.BoundingBox(new C.Geometry.Vector2(0, 0),
                                   new C.Geometry.Vector2(0, 10),
                                   new C.Geometry.Vector2(10, 10),
                                   new C.Geometry.Vector2(10, 0));

var b = new C.Geometry.BoundingBox(new C.Geometry.Vector2(11, 11),
                                   new C.Geometry.Vector2(11, 21),
                                   new C.Geometry.Vector2(11, 21),
                                   new C.Geometry.Vector2(21, 11));

var c = new C.Geometry.BoundingBox(new C.Geometry.Vector2(2, 3),
                                   new C.Geometry.Vector2(2, 7),
                                   new C.Geometry.Vector2(15, 7),
                                   new C.Geometry.Vector2(15, 3));

test("Equals", function () {
    "use strict";
    ok(!a.Equals(b), "shouldn't be equals");
    ok(a.Equals(a), "should be equlas");
});

test("Center", function () {
    "use strict";
    var center = new C.Geometry.Vector2(5, 5);
    ok(a.Center().Equals(center), "Should be equals");
});

test("Intersection", function () {
    "use strict";
    ok(!a.Intersect(b), "Shouldn't intersect");
    ok(a.Intersect(c), "Should Intersect");
});

test("100000 Intersection", function () {
    "use strict";
    var i = 0;
    while (i < 100000) {
        a.Intersect(b);
        ++i;
    }
    expect(0);
});
