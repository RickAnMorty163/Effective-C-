#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

template <typename E>
constexpr auto
toUType(E enumerator) noexcept
{
    return static_cast<std::underlying_type_t<E>>(enumerator);
}

enum class Color : unsigned char
{
    Red,
    Yellow,
    Blue,
    Green,
    Black,
    White
};
signed main()
{
    auto size = sizeof(Color);
    cout << size << endl;
    auto val_ = std::get<toUType(Color::Red)>(std::make_tuple(1, 2, 3));
}
