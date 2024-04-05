#include <iostream>
#include <string>
#include <vector>

class Buffer
{
private:
    unsigned char *_buf;
    int _capacity;
    int _length;

public:
    // explicit关键字：阻止隐式转换的发生
    explicit Buffer(int capacity) : _capacity(capacity), _length(0)
    {
        std::cout << "Buffer (int) capacity " << std::endl;
        // 分配_buf缓冲区
        _buf = capacity == 0 ? nullptr : new unsigned char[capacity]{};
    }
    ~Buffer()
    {
        std::cout << "~ Buffer " << std::endl;
        delete[] _buf;
    }

    Buffer(const Buffer &buffer)
    {
        std::cout << "Copy Buffer now " << std::endl;
        this->_capacity = buffer._capacity;
        this->_length = buffer._length;
        this->_buf = new unsigned char[buffer._capacity];
        std::copy(buffer._buf, buffer._buf + buffer._capacity, this->_buf);
    }

    Buffer(Buffer &&buffer)
    {
        std::cout << " Buffer&& copy now " << std::endl;
        this->_capacity = buffer._capacity;
        this->_length = buffer._length;
        this->_buf = buffer._buf;

        buffer._capacity = 0;
        buffer._length = 0;
        buffer._buf = nullptr;
    }

    Buffer &operator=(const Buffer &buffer)
    {
        std::cout << "Buffer& operator= f " << std::endl;
        if (this != &buffer) // 避免自身赋值
        {
            delete[] this->_buf;
            this->_buf = new unsigned char[buffer._capacity];

            this->_capacity = buffer._capacity;
            this->_length = buffer._length;
            std::copy(buffer._buf, buffer._buf + buffer._capacity, this->_buf);
        }
        return *this;
    }

    Buffer &operator=(const Buffer &&buffer) noexcept
    {
        std::cout << "Buffer&& opeartor= endition" << std::endl;
        if (this == &buffer)
        {
            this->_capacity = buffer._capacity;
            this->_length = buffer._length;

            delete[] this->_buf;
            this->_buf = buffer._buf;
        }
        return *this;
    }
};

signed main()
{
    Buffer buffer(10);
}