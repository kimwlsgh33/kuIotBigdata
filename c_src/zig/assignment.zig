// identifier is a constant
const constant: i32 = 5; // signed 32-bit constant
var variable: u32 = 5000; // unsigned 32-bit variable

// @as performs an explicit type coercion
const inferred_constant = @as(i32, 5);
var inferred_variable = @as(u32, 5000);

// If no known value can be given, the `undefined` value,
// which coerces to any type, may be used as long as a type annotation is provided
const a: i32 = undefined;
var b: u32 = undefined;
