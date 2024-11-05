
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <vector>
class Practice2Solution {
public:
  int countInversions(std::vector<int> numbers) {

    auto cpy = numbers;
    std::vector<int> placeholders(*(std::max_element(numbers.begin(), numbers.end())));

    int numOfInversions = 0;

    for (size_t i = 0; i < numbers.size(); i++) {
      placeholders[numbers[i]] = i;
    }

    std::sort(numbers.begin(), numbers.end());
    for (size_t i = 0; i < numbers.size(); i++) {
      auto dif = abs(placeholders[numbers[i]] - i);
      if (dif != 0)
        numOfInversions += dif;
    }

    return numOfInversions;
  }

  std::vector<int> sortAbsValues(std::vector<int> nums) {
    std::vector<int> placeholders(101);

    for (size_t i = 0; i < nums.size(); i++) {
      placeholders[std::abs(nums[i])]++;
    }

    for (int i = 1; i <= 101; i++)
      placeholders[i] += placeholders[i - 1];

    std::vector<int> outputArray(nums.size());

    for (int i = nums.size() - 1; i >= 0; i--)

    {
      outputArray[placeholders[abs(nums[i])] - 1] = nums[i];

      placeholders[abs(nums[i])]--;
    }

    return outputArray;
  }
};
