module("Floating number comparison");

test("1 / 6 * 6 == 1, tested 100000", function () {
    var a = 1.0 / 6.0;
    var result = true;
    var i = 0;
    while (i < 100000) {
        result = result && C.Utils.Comparison.Equals(a * 6.0, 1.0);
        ++i;
    }
    ok (result, "Should be equals");
});
