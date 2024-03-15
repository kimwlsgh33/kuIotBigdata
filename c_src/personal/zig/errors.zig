const expect = @import("std").testing.expect;
// An error set is like an enum, where each error in the set is a value.
// There are no exceptions in Zig; errors are values.
const FileOpenError = error{
    AccessDenied,
    OutOfMemory,
    FileNotFound,
};

// Error sets coerce to their supersets
const AllocationError = error{OutOfMemory};

test "coerce error from a subset to a superset" {
    const err: FileOpenError = AllocationError.OutOfMemory;
    try expect(err == FileOpenError.OutOfMemory);
}

// An error set type and another type can be combined with the `!` operator to form an error union type.
// Values of these types may be an error value or a value of the other type.
test "error union" {
    const maybe_error: AllocationError!u16 = 10;
    // Here `catch` is used, which is followed by an expression which is evaluated when the value preceding it is an error.
    const no_error = maybe_error catch 0;

    try expect(@TypeOf(no_error) == u16);
    try expect(no_error == 10);
}

// Functions often return error unions.
fn failingFunction() error{Oops}!void {
    return error.Oops;
}

test "returning an error" {
    // `|err|` syntax receives the value of the error.
    // This is called `payload capturing`
    failingFunction() catch |err| {
        try expect(err == error.Oops);
        return;
    };
}

fn failFn() error{Oops}!u32 {
    // `try x` is a shortcut for `x catch |err| return err`
    try failingFunction(); // failingFunction() catch |err| return err
    return 12;
}

test "try" {
    const v = failFn() catch |err| {
        try expect(err == error.Oops);
        return;
    };
    try expect(v == 12); // is never reached
}

// `errdefer` works like `defer` but only executing when the function is returned from with an error inside of the `errdefer` block.
var problems: u32 = 98;

fn failFnCounter() error{Oops}!void {
    errdefer problems += 1;
    try failingFunction();
}

test "errdefer" {
    failFnCounter() catch |err| {
        try expect(err == error.Oops);
        try expect(problems == 99);
        return;
    };
}

// Error unions returned from a function can have thier error sets inferred by not having an explicit error set.
// This inferred error set contains all possible errors that the function may return.
fn createFile() !void {
    return error.AccessDenied;
}

test "inferred error set" {
    //type corecion sucessfully takes place
    const x: error{AccessDenied}!void = createFile();

    //Zig does not let us ignore error unions via _ = x;
    //we must unwrap it with "try", "catch", or "if" by any means
    _ = x catch {};
}

// Error sets can be merged.
const A = error{ NotDir, PathNotFound };
const B = error{ OutOfMemory, PathNotFound };
const C = A || B;

// `anyerror` is the global error set, which due to being the superset of all error sets, can have an error from any set coerced to it.
// Its usage should be generaly avoided.
