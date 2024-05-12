#include <format>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <cstring>
std::string readName1(std::istream &stream)
{
    std::string name;
    while (stream)
    {
        int next = stream.get();
        if (!stream || next == std::char_traits<char>::eof())
            break;
        name += static_cast<char>(next);
    }
    return name;
}
std::string readName2(std::ifstream &stream)
{
    std::string name;
    char next;
    while (stream.get(next)) // 使用另一个重载版本的get(char)，返回一个流的引用
        name += next;
    return name;
}

signed main()
{
    using namespace std;
    fstream fin;
    fin.open(
        "C:/Users/李想/Downloads/VScode_obj/LeetCode/Effective_cpp/test.txt",
        ios::in);
    if (!fin)
    {
        cerr << "get error" << endl;
    }

    fin.close();

    // write ，no use for << operater
    const char *C_string = "this a C foramt stytle\n";
    cout.write(C_string, strlen(C_string));
    // cerr stream
    cerr << "cerr stream is not write to memory for cache\n";

    // iomanip
    // Boolean values
    bool myBool{true};
    cout << "This is a default:" << myBool << endl;
    cout << "This should is true: " << boolalpha << myBool << endl;
    cout << "This should is 1: " << noboolalpha << myBool << endl;
    // setw
    int i{123};
    cout << "this is should be '   123' : " << setw(6) << i << endl;
    // setfill
    cout << "this is should be '000123 : " << setfill('0') << setw(6) << i
         << endl;
    // float format
    auto db1{1.452};
    double db2{5};
    cout << "this is should be ' 5': " << setw(2) << noshowpoint << db2 << endl;
    cout << "this is should br @@1.452 :" << setw(7) << setfill('@') << db1
         << endl;
    cout << "set db1 presion to " << setprecision(3) << db1 << endl;
    cout << "set db2 presion to" << setprecision(2) << db2 << endl;
    cout << format("{:^+4.3}\n", db1); // 等效format

    // time
    time_t t_t{time(nullptr)};
    tm *t{localtime(&t_t)};
    cout << "this should be the current date and time"
         << "format according to your location: " << put_time(t, "%c") << '\n';
    cout.flush();

    // // putback() 在输入流中反向移动一个字符并将放回流中的一个字符作为参数
    // char ch;
    // cin >> ch;
    // cout << format("Retrieved {} before putback('e').", ch) << endl;
    // cin.putback('e');  // 从缓冲区回退一个e,其作为参数返回
    // // cin.unget();//缓冲区回退一个字符
    // cin >> ch;  // 将e写回缓冲区
    // cout << format("Retrievd {} after putback('e').", ch) << endl;

    // getline for cpp
    cout << "Enter multiple lines of text. "
         << "Use an @ character to signal the end of the text .\n";
    string Mystring;
    getline(cin, Mystring, '@');
    cout << format("Read text: \"{}\"", Mystring) << endl;
}