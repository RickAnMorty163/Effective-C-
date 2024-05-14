#include <iostream>
#include <iterator>
#include <string_view>
#include <vector>
using namespace std::string_view_literals;

/**
 * @brief get value from iterator
 *
 * @param Iteroater  it
 * @return template <typename Itername>
 */
// std::iterator_traits<class T>::value_type 迭代器类型萃取
template <typename Itername>
void iteratorTraits(Itername it) {
    typename std::iterator_traits<Itername>::value_type temp;
    temp = *it;
    std::cout << temp << std::endl;
}

/**
 * @brief copy ranges to another target
 *
 * @tparam Itername
 * @param begin
 * @param end
 * @param target
 */
template <typename Itername>
void myCopy(Itername begin, Itername end, Itername target) {
    for (auto it{begin}; it != end; ++it, ++target)
        *target = *it;
}

/**
 * @brief print ranges vlaues
 *
 * @tparam T
 * @param str
 * @param begin
 * @param end
 */
template <typename T>
void PrintRanges(std::string_view str, T begin, T end) {
    std::cout << str << std::endl;
    for (auto it{begin}; it != end; ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

/**
 * @brief Find in Ranges
 *
 * @tparam Iter
 * @param begin
 * @param end
 * @param value
 * @return Iterator for reult
 */
template <typename Iter>
auto myFind(Iter begin, Iter end,
            const typename std::iterator_traits<Iter>::value_type &value) {
    for (auto iter{begin}; iter != end; ++iter) {
        if (*iter == value)
            return iter;
    }

    return end;
}

signed main() {
    // test trait
    std::vector arr{1, 2, 3, 4, 5};
    iteratorTraits(std::begin(arr));

    // test myCopy
    std::vector<int> arr2(5);
    myCopy(std::begin(arr), std::end(arr), std::begin(arr2));
    PrintRanges("arr2", std::begin(arr2), std::end(arr2));

    // test myFind
    auto iter = myFind(std::begin(arr), std::end(arr), 3);
    if (iter != std::end(arr)) {
        std::cout << "find 3 in pos : " << std::distance(std::begin(arr), iter);
    } else {
        std::cout << "not find 3" << std::endl;
    }
}
