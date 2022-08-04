#include <iostream>
#include <unordered_map>

int main() {
  std::unordered_map<char, char> my_map;
  std::cout << my_map.size() << "\n";
  if (my_map['j'] == '\0')
    std::cout << "yes" << std::endl;
  // When we check for existence of a key in a map (as it is done above) and it
  // is absent in the map, it is added to the map and it increases the size of
  // the map by 1. It is added with zero value of the value_type. That is, even
  // if we compare my_map['j'] == 'a', this will add ['j' : '\0'] entry in the
  // map. These facts are true for both std::map and std::unordered_map.
  std::cout << my_map.size() << "\n";
  for (auto p : my_map) {
    std::cout << p.first << ": " << p.second << "\n";
  }
  return 0;
}