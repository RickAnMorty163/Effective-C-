#include <iostream>
#include <algorithm>
constexpr int N = 100010;

// CPP11 推荐使用using声明
using Pit = std::pair<int, int>;
Pit range[N];

signed main()
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> range[i].first >> range[i].second;
    }

    // 最近在研究Cpp语法糖 ：），lambda表达式是个好东西
    sort(range, range + n, [](Pit &a, Pit &b) -> bool
         { return a.second < b.second; });

    int res = 0, ed = -2e9;
    for (int i = 0; i < n; ++i)
    {
        if (ed < range[i].first) // 排除包含和有交集的情况
        {
            res++;
            ed = range[i].second; // 更新到下一个区间
        }
    }

    std::cout << res;
}