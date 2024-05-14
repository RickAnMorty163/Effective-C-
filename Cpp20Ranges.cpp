#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
using namespace std::string_literals;
using std::begin;
/**
 * @author Li Xiang
 * @date 2024 5 13
 *
 */

/**
 * @brief print the ranges than it can be iteratorial
 *
 * @param message
 * @param range
 */
void printRange(std::string_view message, auto &range) {
  std::cout << message << std::endl;
  for (const auto &value : range) {
    std::cout << value << ' ';
  }
  std::cout << std::endl;
}
signed main() {
  std::vector<int> vec{1, 4, 2, 8, 5, 7};
  // std::sort(vec.begin(), vec.end(),
  //           [](const int a, const int b) { return a > b; });

  // ranges提供了一种范围(concept)的约束,这种约束并不局限于容器
  // 以下是range版本的sort算法，相比于标准sort的实现，可以调用更多API进行优化
  std::ranges::sort(vec, [](const int a, const int b) { return 2 * a > b; });
  printRange("now vec is:", vec);
  std::vector values{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // 使用管道操作符, 将values转换为一个range,然后调用sort方法
  // 管道运算符|相当于筛选了ranges，增加了代码可读性
  //  view函数修改了看待范围ranges的方式，即视图
  // 视图具有惰性求值的特性，只有在需要时才进行计算
  std::ranges::sort(values | std::views::drop(3) | std::views::reverse);
  printRange("Now range is: ", values);

  // 注意到某些情况下视图可以修改元素;
  printRange("Before use view to change begin iterator : ", values);
  auto vision = std::views::reverse(values);
  *(begin(vision)) = 42;
  printRange("After use view to change begin iterator : ", values);
  std::cout << "values begin before view create is " << *(values.begin())
            << std::endl;
  auto v = std ::views::reverse(values);

  // 范围工厂 类似Python3中range
  std::ranges::iota_view<int>();         //{0,1,2,3...}
  std::ranges::iota_view(1);             //{1,2,3,4...}
  std::ranges::iota_view(2, 5);          //{2,3,4}
  std::ranges::iota_view('a', 'a' + 26); //{'a','b','c'...'z'}
  // 同样的，范围工厂具有惰性求值的特性，只有当需要时才会生成范围序列

  // 常用std::views函da数
  // reverse(r) 反转视图
  // take(r,n) 取前n个元素
  // drop(r,n) 跳过前n个元素
  // filter(r,pred) 筛选出满足pred的元素，pred返回bool值
  // transform(r,f) 将每个元素应用f函数，返回f(r[i])

  // instance one
  std::vector numbers{1, 2, 3, 4, 5, 6, 7, 8, 8, 9, 10};
  printRange("Before the numbers range:", numbers);

  auto result = numbers | std::views::reverse |
                std::views::filter([](int i) { return i % 2 == 0; }) |
                std::views::transform([](int i) { return i * i; });

  printRange("After the numbers range to get result_view :", result);

  // instance two for ranges factory
  auto result2 =
      std::views::iota(10) |
      std::views::filter([](const auto &value) { return value % 2 == 0; }) |
      std::views::transform([](const auto &value) { return value; }) |
      std::views::take(100);
  printRange("After the numbers range to get result_view :", result2);
}