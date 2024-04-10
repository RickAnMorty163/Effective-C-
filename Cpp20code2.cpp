#include <iostream>
#include <format>
#include <initializer_list>
#include <array>
#include <optional>

using std::cout;
using std::format;

[[maybe_unused]] int makesum(std::initializer_list<int> values)
{
    int total{};
    for (int value : values)
        total += value;
    return total;
}
std::optional<int> getData(bool giveIt)
{
    if (giveIt)
        return 42;
    return {};
}

auto func(int a)
{
    return ++a;
}
signed main()
{
    int Myarray[4]{1, 2, 4};

    const auto [x, y, z, b] = Myarray;

    cout << format("x:{}, y:{}, z:{}, b:{}\n", x, y, z, b);

    for (auto val : Myarray)
        cout << format("{} ", val);

    cout << std::endl;
    std::array<int, 4> arr{1, 2};
    for (auto val : arr)
        cout << format("{} ", val);

    std::pair p1{1, 2LL};

    cout << format("p1.first:{},p1.second:{}\n", p1.first, p1.second);

    auto ini = {1, 2, 3, 4};
    auto res = makesum(ini);
    cout << format("res:{}\n", res);

    auto data1 = getData(false);
    auto data2 = getData(true);

    cout << format("data true {}\n", *data2);

    if (data1.has_value())
    {
        cout << format("data has value\n");
    }
    else
    {
        cout << format("data has no value\n");
    }

    struct st
    {
        std::string name = "unknown";
        int age = 0;
        unsigned long long id = 0;
    };
    st s1 = {"qianshenzhen", 20, 1150122020418};
    st s2 = {.age = 20, .id = 1150122024029};

    cout << s2.name << std::endl;
}