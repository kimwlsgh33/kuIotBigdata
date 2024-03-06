const expect = @import("std").testing.expect;
// all function arguments are immutable
// like const in C
// Unlike variables, which are snake_case,
// functions are camelCase
fn addFive(x: u32) u32 {
    return x + 5;
}

test "function" {
    const y = addFive(0);
    try expect(@TypeOf(y) == u32);
    try expect(y == 5);
}

fn fibonacci(n: u16) u16 {
    if (n == 0 or n == 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// When recursion happens, the zig compiler is no longer able to work out the maximum stack size, which may result in a stack overflow
test "function recursion" {
    const x = fibonacci(10);
    try expect(x == 55);
}
