#include <iostream>
#include <chrono>
#include <math.h>
using std::cout;

class Point
{
    double x = 0, y = 0;

public:
    constexpr Point() = default;
    constexpr Point(const Point &) = default;
    constexpr Point(double x0, double y0) : x(x0), y(y0) {}
    constexpr double getX() { return x; }
    constexpr double getY() { return y; }

    constexpr void setX(double x_vlue) noexcept { x = x_vlue; }
    constexpr void setY(double y_vlue) noexcept { y = y_vlue; }

    constexpr Point reflection(const Point &p)
    {
        Point res;
        res.setX(-res.getX());
        res.setY(-res.getY());
        return res;
    }
};
signed main()
{
    auto st = std::chrono::steady_clock::now();

    constexpr Point p1(1, 2);
    constexpr Point p2(2, 5);

    auto ed = std::chrono::steady_clock::now();
    cout << static_cast<double>((ed - st).count()) / 1e5 << "ms";
}
