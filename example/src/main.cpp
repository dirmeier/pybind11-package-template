#include <iostream>
#include <vector>

#include "clazz.hpp"

int main() {
  std::vector<int> vec{1, 2, 3};
  clazz c(vec);
  std::cout << c << "\n";
  c.add(1);
  std::cout << c << "\n";

  return 0;
}
