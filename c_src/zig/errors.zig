const expect = @import("std").testing.expect;
// there is no expection in Zig
// errors are values
const FileOpenError = error{
    AccessDenied,
    OutOfMemory,
    FileNotFound,
};

const AllocationError = error{OutOfMemory};

test "coerce error from a subset to a superset" {
    // FileOpenError >= AlocationError
    const err: FileOpenError = AllocationError.OutOfMemory;
    try expect(err == FileOpenError.OutOfMemory);
}
