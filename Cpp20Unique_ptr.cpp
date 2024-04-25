#include <iostream>
#include <memory>

using namespace std;
signed main() {
    std::unique_ptr<int> ptr0{make_unique<int>(42)};
    std::cout << *ptr0 << std::endl;
    std::shared_ptr<int> ptr1{make_shared<int>(10)};
    std::weak_ptr<int> ptr2{ptr1};

    if (ptr2.lock()) {
        cout << "ptr2 is not expired" << endl;
    } else {
        cout << "ptr2 is expired" << endl;
    }
    ptr1.reset();
    if (ptr2.lock()) {
        cout << "ptr2 is not expired" << endl;
    } else {
        cout << "ptr2 is expired" << endl;
    }
}