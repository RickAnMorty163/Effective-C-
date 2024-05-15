#include <format>
#include <iostream>

template <typename... Args>
void Print(const Args &...str) {
    ((std::cout << str << " "), ...); // C++17引入了折叠表达式
}
template <typename... Args>
decltype(auto) add(Args... numbers) {
    return ((numbers * 2) + ...);
}

int main() {
    Print("Hello", "World", "!");
    auto add_res{add(11, 2, 3, 4)};
    std::cout << std::format("the add_res is {}\n", add_res);
}