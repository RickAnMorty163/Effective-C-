#include <iostream>
#include <functional>
#include <map>
using std::cin;
using std::cout;

class AA
{
public:
    void operator()(const std::string s)
    {
        cout << s << " : for class function" << '\n';
    }
};
signed main()
{
    std::string s = " Map Container ";

    std::map<std::string, std::function<void(const std::string &)>> map_key;

    std::function<void(const std::string &)> f1 = [&](const std::string &str) -> void
    { cout << s << ": " << "Hello " << str << '\n'; };

    std::function<void(const std::string &)> f2 = [&](const std::string &str) -> void
    { cout << s << ": " << str << " Hello" << '\n'; };

    std::function<void(const std::string &)> f3 = AA();

    map_key.insert({"before", f1});
    map_key.insert({"after", f2});
    map_key.insert({"class", f3});

    map_key["before"]("Rust");
    map_key["after"]("Rust");
    map_key["class"]("Rust");
}