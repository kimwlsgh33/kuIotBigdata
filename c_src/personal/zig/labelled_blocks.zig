const expect = @import("std").testing.expect;
// Blocks in Zig are expressions and can be given labels, which are used to yield values, meaning they can be used in place of a value.
// The value of an empty block `{}` is a value of the type `void`.
test "labelled blocks" {
    const count = blk: {
        var sum: u32 = 0;
        var i: u32 = 0;
        while (i < 10) : (i += 1) sum += i;
        break :blk sum;
    };
    try expect(count == 45);
    try expect(@TypeOf(count) == u32);
}

// This can be seen as being equivalent to C's `i++`
test "C's i++" {
    var i: u32 = 0;
    const rs = blk: {
        const tmp = i;
        i += 1;
        break :blk tmp;
    };
    try expect(rs == 0);
}
