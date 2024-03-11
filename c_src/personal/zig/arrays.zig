// [N]T
// `N` is the number of elements
// `T` is the type of those elements
const a = [5]u8{ 'h', 'e', 'l', 'l', 'o' };
// `N` may be replaced by `_` to infer the size of the array
const b = [_]u8{ 'w', 'o', 'r', 'l', 'd' };

const length = a.len; // 5, array has a len member
