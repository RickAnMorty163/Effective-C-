#include <any>
#include <format>
#include <iostream>
using namespace std;
std::any ANY(int x, double y) { return std::any(x + y); }
// Cpp17 standerd std::any 强类型安全容器, 适用于返回未知类型的情况
// 在堆上实现分配，效率略低于std::optional和 std::variant
signed main() {
    auto res = ANY(1, 4.23);
    if (res.has_value()) {
        cout << format("{}", std::any_cast<double>(res)) << "\n";
    }

    any a;
    any b{"str::any for cpp 17"s}; // 初始化注意std::string的字面量问题

    if (a.type() == typeid(void)) {
        cout << format("{}\n", "a is void");
    } else {
        std::cerr << "Wrong Type" << std::endl;
    }

    if (b.type() == typeid(std::string)) {
        auto Str = std::any_cast<std::string>(b);
        cout << format("{}\n", Str);

    } else {
        std::cerr << "Wrong Type" << std::endl;
    }
}