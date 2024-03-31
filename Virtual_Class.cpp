#include <iostream>

using std::cin;
using std::cout;

signed main()
{
    auto name = (std::string) "Rust";
    auto func = [=](auto s) -> void
    { cout << name << " " << s << std::endl; };
    func(" , Hello ! ");
}
