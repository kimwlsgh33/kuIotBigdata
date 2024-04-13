const expect = @import("std").testing.expect;
// Zig supports hex, octal and binary integer literals.
const decimal_int: i32 = 98222;
const hex_int: u8 = 0xff;
const another_hex_int: u8 = 0xFF;
const octal_int: u16 = 0o755;
const binary_int: u8 = 0b11110000;

// Underscores may also be placed between digits as a visual separator.
const one_billion: u64 = 1_000_000_000;
const binary_mask: u64 = 0b1_1111_1111;
const permissions: u64 = 0o7_5_5;
const big_address: u64 = 0xFF80_0000_0000_0000;

// "Integer Widening" is allowed, which means that integers of a type may coerce to an integer of another type, providing that the new type can fit all of the values that the old type can.
test "integer widening" {
    const a: u8 = 250;
    const b: u16 = a;
    const c: u32 = b;
    try expect(c == a);
}

// If you have a value stored in an integer that cannot coerce to the type that you want, `@intCast` may be used to explicitly convert from one type to the other.
// If the value given is out of the range of the destination type, this is detectable illegal behaviour.
test "@intCast" {
    const x: u64 = 200;
    const y = @as(u8, @intCast(x));
    try expect(@TypeOf(y) == u8);
}

// Integers, by default, are not allowed to overflow.
// Overflows are detectable illegal behaviour.
// Sometimes, being able to overflow integers in a well-defined manner is a wanted behaviour.
// For this use case, Zig provides overflow operators.

// +, +%
// -, -%
// *, *%
// +=, +=%
// -=, -=%
// *=, *=%
test "well defined overflow" {
    var a: u8 = 255;
    a +%= 1;
    try expect(a == 0);
}
