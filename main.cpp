/*#include "iterators/iterators.cpp"*/
/*#include "sorts/sorts.cpp"*/
#include "practice2/practice2.cpp"
#include <iostream>

int main() {
  std::string word = "alporfmdqsbhncwyu";
  Practice2Solution solutions;

  int res = solutions.minimumPushes(word);

  std::cout << res << std::endl;
}
