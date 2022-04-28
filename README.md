# ceser

ceser is a C binary serialization library.

You simply read and write to/from a byte buffer using `read_SUFFIX(...)` and `write_SUFFIX(...)` where `SUFFIX` is the desired data type.

Basic data types supported:

`u8`, `u16`, `u32`, `u64`,

`i8`, `i16`, `i32`, `i64`,

`f32`, `f64`

Floating point types are `IEEE754` standard compliant. Implementation can be found in `src/float_ieee754.c`.

License:
---
ceser is licensed under the terms of MIT license