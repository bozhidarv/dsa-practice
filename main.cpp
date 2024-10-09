#include "iterators/iterators.cpp"
#include <iostream>

int main() {
  std::vector<int> tst = {2, 2, 4, 5};
  IteratorSolutions s;

  std::cout << s.partitionArray(tst, 0) << std::endl;

  return 0;
}
