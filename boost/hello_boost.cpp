#include <iostream>
#include <boost/array.hpp>

int main() {
  boost::array<int, 4> iarr = {1, 2, 3, 4};
  for (const auto x : iarr) {
    std::cout << "Boost arr value: " << x << "\n";
  }
  return 0;
}