#include <iostream>
#include <random>
/**
 * @param std::string& for accept a string object or C format char
 * @param std::string& for accept a string object or C format char
 * @return std::string it is a value
 * @brief the function is return a string rvalue object for s1 and s2 conect
 * @details the function may throw some exception like accept C format cahr
 * and string object at the same time
 */
const std::string Strcat(const std::string &s1, const std::string &s2) {
  return s1 + s2;
}

/**
 * @param size_t if not give a paramter , that will be 8
 * @brief this function is make a random string with t numbers
 * @return const string& randomSquence
 */
const std::string RandomString(std::size_t t = 8) {
  std::string randomSequence;
  while (t) {
    auto randSeed{65 + std::rand() % (122 + 1 - 65)};
    if (randSeed >= 91 && randSeed <= 96)
      continue;
    randomSequence += static_cast<char>(randSeed);
    t--;
  }
  return randomSequence;
}

signed main() {
  auto s_one{RandomString(42)};
  auto s_two{RandomString(10)};
  auto s_noparam{RandomString()};
  std::cout << s_one << std::endl;
  std::cout << s_two << std::endl;
  std::cout << s_noparam << std::endl;
}