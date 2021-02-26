// Let's try to recreate this Rust code:
//
// enum AwesomeEnum {
//     AwesomeNumber(i32),
//     NotAwesomeString(String),
//     Nothing
// }
//
// fn awesome_function(value: i32) -> AwesomeEnum {
//     if value == 1 {
//         return AwesomeEnum::AwesomeNumber(value);
//     } else if value == 2 {
//         return AwesomeEnum::NotAwesomeString(String::from("YAY!"));
//     } else {
//         return AwesomeEnum::Nothing;
//     }
// }
//
// fn main() {
//     let number: i32 = <NUMBER HERE>;
//     let result = awesome_function(number);
//
//     match result {
//         AwesomeEnum::AwesomeNumber(v) => println!("Returned number: {}", v),
//         AwesomeEnum::NotAwesomeString(v) => println!("Returned string: {}", v),
//         AwesomeEnum::Nothing => println!("Absolutely nothing...")
//     }
// }

#include <variant> // We're gonna be using variants for this!
#include <boost/hana/functional/overload.hpp> // Boost's overload helps with recreating the match.
#include <string>
#include <iostream>

// An std::variant simply contains either one of the types specified in the template argument.
// All you gotta do is simply return the type you wish.
// I am not using "named" return values for the std::variant, which means when we're gonna be
// matching it in our main function, we won't have a nice name like AwesomeEnum::AwesomeNumber.
// However, you can do that using structs which hold a value. Rust enums make this process
// much easier.

// std::monostate is the traditional way to return "nothing" in an std::variant.

std::variant<int, std::string, std::monostate> awesome_function(int value) {
    if (value == 1) {
        return value;
    } else if (value == 2) {
        return "YAY!";
    } else {
        return std::monostate();
    }
}

int main() {
    int value;
    std::cin >> value;

    // In order to mimic the match keyword from Rust, you can use std::visit.
    // There is no good way to do this in C++ though, without being overly verbose.
    // But, you can use something called an "overload" pattern.
    // You don't have to use boost, but this helps us avoid writing weird template magic.
    // If you don't wanna use boost then look up std::visit documentation.
    std::visit(boost::hana::overload (
        // the visit will call the correct function depending on the type it contains!
        [&](int v) { std::cout << "Returned number: " << v << std::endl; },
        [&](std::string v) { std::cout << "Returned string: " << v << std::endl; },
        [&](std::monostate v) { std::cout << "Absolutely nothing..." << std::endl; }
    ), awesome_function(value));
}
