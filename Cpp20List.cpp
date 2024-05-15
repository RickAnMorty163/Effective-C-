#include <format>
#include <forward_list>
#include <iostream>
#include <list>

/**
 * @brief 正向迭代器遍历输出
 *
 * @tparam T
 * @param begin
 * @param end
 */
template <typename T>
void PrintRanges(T begin, T end) {
    std::cout << "Now List is : " << std::endl;
    for (auto it{begin}; it != end; ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}
int main(int argc, char const *argv[]) {
    // List容器封装了双链表，不支持随机读写迭代器
    // List 的插入删除都是常量时间复杂度
    std::list L1{1, 2, 2, 3, 3, 4};
    L1.push_back(5);
    L1.push_front(0);
    L1.emplace_back(42);
    PrintRanges(std::begin(L1), std::end(L1));
    std::cout << std::format("L1's  size() now is {}\n", L1.size());
    // 由于标准库中的STL算法可能会使用到随机访问迭代器，所以List中实现了一些常用算法
    L1.reverse();
    PrintRanges(std::begin(L1), std::end(L1));
    L1.remove_if([](const int value) { return value > 4 && value < 42; });
    PrintRanges(std::begin(L1), std::end(L1));

    L1.reverse();
    // unique相邻元素去重(可以提供二元谓词自定义去重方式)，因为list插入和删除元素的效率比较高
    auto count_delete = L1.unique(
        [](const int value1, const int value2) { return value1 == value2; });
    std::cout << std::format("unique delete {} elements\n",
                             count_delete); // Cpp20
    PrintRanges(std::begin(L1), std::end(L1));

    // forward_list封装了单链表，只支持前向迭代器，一般认为效率高于list,但是也
    // 阉割了一些List的功能

    std::forward_list l0{1, 2, 2, 3, 3, 4, 5};
    l0.push_front(0); // forward_list仅支持头插，因为尾插效率十分底下
    PrintRanges(std::begin(l0), std::end(l0));
    l0.reverse();

    auto l0_unique_delete = l0.unique(
        [](const int value1, const int value2) { return value1 == value2; });
    std::cout << std::format("unique delete {} elements\n", l0_unique_delete);

    PrintRanges(std::begin(l0), std::end(l0));
    l0.sort([](const int value1, const int value2) { return value1 < value2; });
    PrintRanges(std::begin(l0), std::end(l0));

    // 由于单链表难以访问前一个元素，因此只能在forward_list上提供前开的范围 (...
    // 特别的,forward_list提供了一个指向头结点的before_begin()迭代器用于构建迭代范围
    // before_begin()+1的效果相当于begin()返回的迭代器
    auto head_iter = l0.before_begin();
    std::cout << std::format("head_iter to next node (first value) is {}\n",
                             *(++head_iter));
}