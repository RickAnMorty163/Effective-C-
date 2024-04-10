#include <iostream>
#include <compare>
#include <format>
#include <limits>

using std::format;
using std::numeric_limits;
namespace First::second
{
    double a{};
    double b{};
}
namespace First::third
{
    double a{};
    double b{};
}

enum class NFA : unsigned int
{
    True = 1,
    False = 0,
    Default = numeric_limits<unsigned int>::max()
};

enum class Mode
{
    Default,
    Custom,
    Standard
};
[[nodiscard("some things you are ignore")]] int func(int a)
{
    return a + 1;
}

[[maybe_unused]] auto func2()
{
    std::cout << format("The function is not do some work ^_^");
}
signed
main()
{
    double a{};
    double *ptr{};

    if (ptr == nullptr && a == 0)
        std::cout << format("right, ptr=nullptr,a={}\n", a);

    std::cout << format("First::second::a={}\n", First::second::a);
    std::cout << format("First::third:: a= {}\n", First::third::a);

    auto range{0};

    std::cout << format("Max double is {}\n", numeric_limits<double>::max());
    std::cout << format("Min double is {}\n", numeric_limits<double>::min());
    std::cout << format("Lowest double is {}\n", numeric_limits<double>::lowest());

    using NFA::True;

    NFA n1 = {True};
    NFA n2 = {NFA::False};

    int value{0};
    Mode mode{Mode::Custom};
    switch (mode)
    {
        using enum Mode;
    case Custom:
        value = 84;
        [[fallthrough]];
    case Standard:
    case Default:
        std::cout << format("switch case end !\n");
    }
}