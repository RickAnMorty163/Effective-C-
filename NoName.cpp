#include <iostream>

using namespace std;

signed main()
{
    int a = 10;

    int arr[4] = {1, 2, 3, 4};
    int(*ptr)[4] = &arr;

    &"Hello World";
    const char str[12] = "Hello World";
    const char(*str0) = "Hello World";
}