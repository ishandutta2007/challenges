/*

Problem:

In your choice of language, write the shortest function that returns the floor of the square root of an unsigned 64-bit integer.

Test cases:

Your function must work correctly for all inputs, but here are a few which help illustrate the idea:

               INPUT ⟶ OUTPUT

                   0 ⟶  0
                   1 ⟶  1
                   2 ⟶  1
                   3 ⟶  1
                   4 ⟶  2
                   8 ⟶  2
                   9 ⟶  3
                  15 ⟶  3
                  16 ⟶  4
               65535 ⟶ 255
               65536 ⟶ 256
18446744073709551615 ⟶ 4294967295
Rules:

You can name your function anything you like. (Unnamed, anonymous, or lambda functions are fine, as long as they are somehow callable.)
Character count is what matters most in this challenge, but runtime is also important. I'm sure you could scan upwards iteratively for the answer in O(√n) time with a very small character count, but O(log(n)) time would really be better (that is, assuming an input value of n, not a bit-length of n).
You will probably want to implement the function using purely integer and/or boolean artithmetic. However, if you really want to use floating-point calculations, then that is fine so long as you call no library functions. So, simply saying return (n>0)?(uint32_t)sqrtl(n):-1; in C is off limits even though it would produce the correct result. If you're using floating-point arithmetic, you may use *, /, +, -, and exponentiation (e.g., ** or ^ if it's a built-in operator in your language of choice, but only exponentiation of powers not less than 1). This restriction is to prevent "cheating" by calling sqrt() or a variant or raising a value to the ½ power.
If you're using floating-point operations (see #3), you aren't required that the return type be integer; only that that the return value is an integer, e.g., floor(sqrt(n)), and be able to hold any unsigned 32-bit value.
If you're using C/C++, you may assume the existence of unsigned 64-bit and 32-bit integer types, e.g., uint64_t and uint32_t as defined in stdint.h. Otherwise, just make sure your integer type is capable of holding any 64-bit unsigned integer.
If your langauge does not support 64-bit integers (for example, Brainfuck apparently only has 8-bit integer support), then do your best with that and state the limitation in your answer title. That said, if you can figure out how to encode a 64-bit integer and correctly obtain the square root of it using 8-bit primitive arithmetic, then more power to you!
Have fun and get creative!

*/

fn main() {
    assert_eq!(isqrt(0), 0);
    assert_eq!(isqrt(1), 1);
    assert_eq!(isqrt(2), 1);
    assert_eq!(isqrt(3), 1);
    assert_eq!(isqrt(4), 2);
    assert_eq!(isqrt(8), 2);
    assert_eq!(isqrt(9), 3);
    assert_eq!(isqrt(15), 3);
    assert_eq!(isqrt(16), 4);
    assert_eq!(isqrt(65535), 255);
    assert_eq!(isqrt(65536), 256);
    assert_eq!(isqrt(18446744073709551615), 4294967295);
}

fn isqrt(x: u128) -> u128 {
    let mut s = f64::floor(f64::sqrt(x as f64)) as u128;
    if s*s >= u64::MAX.into() {
        s = u32::MAX.into();
    }
    s
}

