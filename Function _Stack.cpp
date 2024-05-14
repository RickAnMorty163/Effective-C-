#include <iostream>

[[maybe_unused]] void Warning(int *ptr1) {
    ptr1 = new int(
        10); // 危险操作，函数栈销毁后ptr1不再指向堆区内存，该内存无法被释放，造成内存泄漏
}

void Heap_int(int **ptr2) // 传二级指针防止内存泄漏
{
    *ptr2 = new int(10); // 将new开辟的堆区内存地址给一级指针ptr1;
}
// 函数生命周期结束时仅释放二级指针
signed main() {
    int res = 42;
    int *ptr1 = &res;
    Heap_int(
        &ptr1); // 参数不能写成(&(&res))的形式，因为&res是一个右值，对右值取地址是非法的
    std::cout << *ptr1 << std::endl;
    delete ptr1;    // 销毁堆区内存
    ptr1 = nullptr; // 置空指针，防止垂悬引用
}