/**
 * @file Cpp20Work
 * @author Li Xiang
 * @brief expriment cpp20 concept
 * @details use some simple instances to test cpp20 concept feature
 * @version 0.1.0
 * @date 2024-4-26
 */
#include <iostream>
using namespace std;

template <typename T>
concept SetSize = sizeof(T) == 4;

// 简单的require子句
template <typename T>
concept Incrementable = requires(T x) {
    x++;
    ++x;
}; // T x必须支持前缀自增和后缀自增

// concept同样支持使用逻辑运算符嵌套
template <typename T>
concept UnionCheck = SetSize<T> && Incrementable<T>;

//  类型require
template <typename T>
concept Jugement = requires { typename T::value; }; // 检查T是否包含value成员

// 复合require
//{expression} noexcept -> type-constraint , 后两项均是可选的
template <typename T>
concept CheckSwap = requires(T x, T y) {
    { x.swap(y) } noexcept; // 检查x.swap(y)是否是noexcept的方法
};

// 方法类型转换判断
// template <typename T>
// concept CheckType = requires(const T x) {
//     {
//         x.size()
//     }
//     -> convertible_to<
//         size_t>;  //
//         检测size()方法的返回值类型是否为size_t，不知道为什么GCC13.2不支持
// };

// 嵌套的require
template <typename T>
concept CheckSize_Operator = requires(T x) {
    // sizeof(T) = 4;
    x++;
    x--;
    ++x;
    --x;
};

//<concept>标准库中预定义的一些基本概念
// template <typename T>
// concept IsDerived = derived_from<T, foo>;  // 检查T是否是派生于foo类

template <typename T>
concept IsConventible2Bool =
    convertible_to<T, bool>; // 检查T是否可以转换为bool类型

template <typename T>
concept DefalultAndCopyConstructible =
    default_initializable<T> &&
    copy_constructible<T>; // T既可以默认构造，也可以拷贝构造

// 模板类型约束

// method 1 直接给模板参数T添加约束
template <UnionCheck T> void Change(T x) {
    std::cout << "T is a UnionCheck type" << std::endl;
    std::cout << "T x++ " << x++ << std::endl;
    std::cout << "T ++x " << ++x << std::endl;
    std::cout << "T x-- " << x-- << std::endl;
    std::cout << "T --x " << --x << std::endl;
    std::cout << "sizeof T " << sizeof(T) << std::endl;
}
// method2 使用requires子句添加约束
template <typename T>
    requires UnionCheck<T>
void hello(T x) {
    std::cout << "hello , " << x << " world ! " << std::endl;
}

// method3 使用requires+常量表达式
template <typename T>
int Additon(T x)
    requires requires(
        T x) // 注意是两个requires,requires子句也可以放在函数头之后
{
    x++;
    ++x;
}
{
    std::cout << "stack in" << std::endl;
    x++;
    ++x;
    return x;
}
signed main() {
    // Incrementable auto a  {make_unique<int>(42)};

    // concept对auto的类型推导进行约束
    Incrementable auto b{new int{42}};
    cout << *b << endl;

    SetSize auto S{42};
    Incrementable auto I{42};
    // UnionCheck 是 SetSize && Incrementable 的复合约束
    UnionCheck auto INT{42};

    Change(42);

    delete b;
    b = nullptr;
}