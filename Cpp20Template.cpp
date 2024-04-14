#include <format>
#include <iostream>

using namespace std;
decltype(auto) Compare(const auto& a, const auto& b) {
    return a > b ? a : b;
}

signed main() {
    auto res{Compare(1, 2.45)};
    cout << format("The bigger is {:< 10}", res);
}