// for loops are used to iterate over arrays
test "for" {
    // character literals are equivalent to integer literals
    const string = [_]u8{ 'a', 'b', 'c' };

    // iterate from 0 to infinite
    for (string, 0..) |character, index| {
        // You have to use `_` because zig doesn't allow us to have unused values
        // '_' is cannot be used at global scope
        _ = character;
        _ = index;
    }

    for (string) |character| {
        _ = character;
    }

    for (string, 0..) |_, index| {
        _ = index;
    }

    for (string) |_| {}
}
