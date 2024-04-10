#include <iostream>
#include <format>
#include <vector>

// 普通函数的通用引用
template <typename T>
void func(T &&parm) // 万能引用,可以接受左值和右值
{
    std::cout << "T&& " << std::endl;
}

// 可变参数模板的参数引用
template <typename... Args>
void func2(Args &&...args)
{
    std::cout << "Args&&" << std::endl;
}

signed main()
{
    int a = 10, b = 42;
    func(a); // 发生引用折叠，因为a是左值
    func(10);

    func2(1, 2, 3, 4, 5); // 类似func的行为
    func2(a, b);

    // auto的通用引用
    auto timeFunction = [](auto &&func)
    { std::forward<decltype(func)>(func);std::cout << "auto&&" << std::endl; };
    // std::forward不能自动推导模板参数，所以需要手动指定
}