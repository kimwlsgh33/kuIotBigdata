const expect = @import("std").testing.expect;
// Zig provides a level of safety, where problems may be found during execution.
// Safety can be left on, or turned off.
// Zig has many cases of so-called "detectable illegal behaviour", meaning that illegal behaviour will be caught (causing a panic) with safety on, but will result in undefined behaviour with safety off.
// Users are strongly recommended to develop and test their software with safety on, despite its speed penalties.

// For example, runtime safety protects you from out of bounds indices.
// test this!
// test "out of bounds" {
//     const a = [3]u8{ 1, 2, 3 };
//     const index: u8 = 5;
//     const b = a[index];
//     _ = b;
// }

// The user may disable runtime safety for the current block using the built-in function `@setRuntimeSafety`.
// test "out of bounds, no safety" {
//     @setRuntimeSafety(false);
//     const a = [3]u8{ 1, 2, 3 };
//     const index: u8 = 5;
//     const b = a[index];
//     _ = b;
// }

// `unreachable` is an assertionto the compiler that this statement will not be reached.
// It can tell the compiler that a branch is impossible, which the optimiser can then take advantage of.
// Reaching an `unreachable` is detectable illegal behaviour.
// As it is of the type `noreturn`, it is compatible with all other types. Here it coerces to u32.
// test "unreachable" {
//     const x: i32 = 1;
//     const y: u32 = if (x == 2) 5 else unreachable;
//     _ = y;
// }

fn asciiToUpper(x: u8) u8 {
    return switch (x) {
        'a'...'z' => x + 'A' - 'a',
        'A'...'Z' => x,
        else => unreachable,
    };
}
// Here is an unreachable being used in a switch.
test "unreachable switch" {
    try expect(asciiToUpper('a') == 'A');
    try expect(asciiToUpper('A') == 'A');
}
