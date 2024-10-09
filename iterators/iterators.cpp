#include <algorithm>
#include <functional>
#include <iterator>
#include <string>
#include <vector>

class IteratorSolutions {
public:
  bool canBeEqual(std::vector<int> &target, std::vector<int> &arr) {
    std::sort(target.begin(), target.end());
    std::sort(arr.begin(), arr.end());
    for (size_t i = 0; i < arr.size(); i++) {

      if (target.at(i) != arr.at(i)) {
        return false;
      }
    }
    return true;
  }

  double minimumAverage(std::vector<int> &nums) {
    std::vector<double> averages;
    size_t n = nums.size();
    for (size_t i = 0; i < n / 2; i++) {
      auto min = std::min_element(nums.begin(), nums.end());
      double minNum = *min;
      nums.erase(min);
      auto max = std::max_element(nums.begin(), nums.end());
      double maxNum = *max;
      nums.erase(max);

      averages.push_back((minNum + maxNum) / 2.0);
    }
    return *std::min_element(averages.begin(), averages.end());
  }

  int maxProduct(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    int largestNum = nums[nums.size() - 1];
    nums.pop_back();
    return (largestNum - 1) * (nums[nums.size() - 1] - 1);
  }

  std::vector<std::string> sortPeople(std::vector<std::string> &names,
                                      std::vector<int> &heights) {
    std::vector<std::string> sorted;
    size_t n = names.size();
    for (size_t i = 0; i < n; i++) {
      auto biggestHeight = std::max_element(heights.begin(), heights.end());
      size_t tallestPersonIdx = std::distance(heights.begin(), biggestHeight);

      sorted.push_back(names[tallestPersonIdx]);
      heights.erase(biggestHeight);
      names.erase(names.begin() + tallestPersonIdx);
    }
    return sorted;
  }

  int partitionArray(std::vector<int> &nums, int k) {
    std::sort(nums.begin(), nums.end());
    int numOfPartitions = 0;

    for (size_t i = 0; i < nums.size(); i++) {
      for (size_t j = i; j < nums.size(); j++) {
        if (nums[j] - nums[i] > k) {
          numOfPartitions++;
          --j;
          i = j;
          break;
        }
        if (j == (nums.size() - 1)) {
          numOfPartitions++;
          i = j;
          break;
        }
      }
    }

    return numOfPartitions;
  }
};
