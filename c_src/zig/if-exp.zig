// Zig's if statements accept `bool` values (i.e. `true` or `false`)
// Unlike C and Javascript, there are no values that implicitly coerce to bool value

const expect = @import("std").testing.expect;

test "if statement" {
    const a = true;
    var x: u16 = 0;
    if (a) {
        x += 1;
    } else {
        x += 2;
    }
    try expect(x == 1);
}

test "if statment expression" {
    const a = true;
    var x: u16 = 0;
    // `if statement` has a return value == expression
    x += if (a) 1 else 2;
    try expect(x == 1);
}
