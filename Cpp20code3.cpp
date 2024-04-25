#include <format>
#include <iostream>
#include <string>

using namespace std;

string_view extractExtension(string_view filename) {
    return filename.substr(filename.rfind('.'));
}

signed main() {
    auto s1{"hello world"s};
    std::string_view sv1{s1};
    const char* str{R"--(Hello,() world!)--"};  // 拓展字面量
    std::cout << std::format("{}\n", sv1);

    auto FILENAME{"HelloWorld.cpp"s};
    cout << format("CPP style string : {}\n", extractExtension(FILENAME));

    auto CSTRING{"CSTRING.c"};
    cout << format("C style string : {}\n", extractExtension(CSTRING));

    auto i{42};
    cout << format("|{}|\n", i);
    cout << format("|{:+05B}|\n", i);   // 二进制
    cout << format("|{:^010X}|\n", i);  // 十六进制
    cout << format("|{:<5}|\n", i);
    cout << format("|{:> 5}|\n", -42);

    constexpr auto RES{3.14 / 2.17};

    cout << format("|{:^+10e}|", RES);
    cout << format("|{:^+010.7}|", RES);
    cout << format("|{:^+10g}|", RES);
}