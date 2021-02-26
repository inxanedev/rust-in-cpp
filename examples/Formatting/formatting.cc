// Rust's I/O macros like println!() can have {} inside their format string.
// Those {}s will be replaced with the stringified versions of the macro's arguments.
// For example, you can put a string or integer there and it'll be replaced.
//
// println!("Hello, {}!", 5);
//
// The code above would print Hello, 5!
//
// In standard C++, you would write that as:
//
// std::cout << "Hello, " << 5 << "!" << std::endl;
//
// As you can see, it is quite annoying to type all these operators and it's prone to mistakes.
// Plus, it's quite difficult to change the code, and also it's quite hard to read.
//
// There are proposals to include formatting just like Rust's macros into standard C++.
// It's even in the C++20 standard, but no compilers support it yet.
//
// For now, if you don't wanna roll your own solution, you'll have to use a library.
// And for that, I recommend {fmt}!
//
// https://fmt.dev

#include <fmt/core.h>

int main() {
    fmt::print("Hello, {}!\n", 5);
}
