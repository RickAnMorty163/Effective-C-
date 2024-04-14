#include <iostream>

using namespace std;

// 优先使用delete删除而不是设置为private属性

struct B;

struct A {
    A(int data) : _data(_data){};
    A(const A& a) = delete;
    A& operator=(const A&) = delete;

   private:
    friend B;
    int _data;
};

struct B {
    B() {
        A a(10);
        // A b = a;
    }
};

bool is_Lucky(int a) {
    return a == 7;
}

bool is_Lucky(char a) = delete;  // 避免传入char类型的强制转换

template <typename T>
void processPoint(T* ptr) {}

template <>
void processPoint(void* ptr) = delete;  // 删除模板的<void*>特例化

signed main() {
    auto x = is_Lucky(42);
    // auto y = is_Lucky('5');

    int aa = 10;
    auto aaptr = static_cast<void*>(&aa);

    // processPoint(aaptr);
}