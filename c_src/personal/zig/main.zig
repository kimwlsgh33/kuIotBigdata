// Prerequisites
// 1. This `main.zig` file is UTF-8 encoded as the Zig compiler does not currently support other encodings
// use zig standard libary
const std = @import("std");

pub fn main() void {
    std.debug.print("Hello, {s}!\n", .{"World"});
}
