#include <optional>
#include <iostream>

// This function returns 42 if the supplied value wasn't 15.
// If it was, the function returns nothing.
//
// Equivalent to this rust code:
//
// fn get_number_if_not_15(value: i32) -> Option<i32> {
//     if value != 15 {
//         return Some(42);
//     } else {
//         return None;
//     }
// }
std::optional<int> get_number_if_not_15(int value) {
    if (value != 15)
        return 42;

    // this is how you return nothing/empty, (or Rust's 'None').
    return {};
}

int main() {
    int input;
    std::cin >> input;

    // auto here refers to std::optional<int>.
    auto result = get_number_if_not_15(input);

    // you don't have to call .has_value() here, you can omit it as well!
    if (result.has_value()) {
        std::cout << "Function returned a value! " << result.value() << std::endl;
    } else {
        std::cout << "Function didn't return any value :(" << std::endl;
    }
}
