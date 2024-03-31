#include <iostream>
#include <algorithm>
#include <vector>

// template <class C>
// auto cbegin(const C &Container)
// { // 设计cbegin
//     return std::begin(Container);
// }

template <typename C, typename V>
auto find_and_insert(C &Container, const V &targetval, const V &insertval)
{
    auto it = std::find(cbegin(Container), cend(Container), targetval);
    Container.insert(it, insertval);
}

signed main()
{
    std::vector<int> val = {1, 3, 24, 5};

    auto it = std::find(val.cbegin(), val.cend(), 3); // cpp11 原生支持const迭代器

    find_and_insert<std::vector<int>, int>(val, 3, 5);

    for (auto v : val)
    {
        std::cout << v << ' ';
    }
}