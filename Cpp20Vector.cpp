#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std::string_literals;
void printRange(std::string_view message, auto &range) {
    std::cout << message << std::endl;
    for (const auto &value : range) {
        std::cout << value << ' ';
    }
    std::cout << std::endl;
}

// const迭代器只读
// const_iterator不能强制转换为iterator
// 对于一个const修饰的vector，默认使用const迭代器进行访问元素操作
template <typename T>
[[maybe_unused]] void iteratorRange(const typename std::vector<T> &v) {
    for (typename std::vector<T>::itertor iter{v.cbegin()}; iter != v.end();
         iter++)
        std::cout << *iter << " ";
    std::cout << std::endl;
}

signed main() {
    std::vector v1{1, 2, 3, 4};

    printRange("v1: ", v1);
    // 重新初始化vector容器
    v1.assign({4, 3, 2, 1});
    printRange("v1: ", v1);

    // cpp20中引入STL算法std::erase_if()可以在线性时间复杂度内完成筛选元素的操作
    // 第二个参数可以自定义筛选条件,即一个lambda表达式
    std::erase_if(v1, [](const int value) {
        if (value % 2 == 0)
            return true;
        return false;
    });

    printRange("after erase"s, v1);

    // 在vector容器中存储引用
    std::string str1{"Hello "s};
    std::string str2{"World "s};
    std::vector<std::reference_wrapper<std::string>> ref_vec{std::ref(str1),
                                                             std::ref(str2)};
    // std::reference_wrapper的get方法返回引用的原始的对象
    ref_vec[0].get() += ',';
    ref_vec[1].get() += '!';

    std::cout << "str1 " << str1 << std::endl;
    std::cout << "str2 " << str2 << std::endl;

    // instance to use vector container
    std::vector vec1{1, 2, 3, 5};
    std::vector vec2(0, 0);

    // insert的插入位置在当前迭代器位置的前面
    vec1.insert(std::cbegin(vec1) + 3, 4);
    printRange("now vec1 after insert is", vec1);

    for (int i{6}; i <= 10; ++i)
        vec2.push_back(i);
    printRange("now vec2 after push_back is", vec2);

    vec1.insert(std::cend(vec1), std::begin(vec2), std::end(vec2));
    printRange("now vec1 after insert is", vec1);

    vec2.clear();
    vec2.insert(std::begin(vec2), 10, 100);
    printRange("now vec 2 is", vec2);

    // 移动语义
    std::string str0(2, 'A');
    std::vector<std::string> vec_string;
    vec_string.push_back(std::move(str0));
    printRange("now vec_string is", vec_string);

    auto ref_emplace = vec_string.emplace_back(5, 'a');
    printRange("now vec_string is", vec_string);
    std::cout << ref_emplace << std::endl;

    // cpp20 std::ssize（） -> 有符号整形长度
    auto length = std::ssize(vec_string);

    // tips: 回收vector内存->与空的临时vector匿名对象交换
    std::vector<int> vec_big(1000);
    std::vector<int>().swap(vec_big);
}