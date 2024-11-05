#include <algorithm>
#include <cmath>
#include <cstddef>
#include <string>
#include <vector>

class Practice2Solution {
private:
  static bool closer(const std::vector<int> &point1, const std::vector<int> &point2) {
    auto dist1 = std::sqrt((point1[0] - 0) * (point1[0] - 0) + (point1[1] - 0) * (point1[1] - 0));

    auto dist2 = std::sqrt((point2[0] - 0) * (point2[0] - 0) + (point2[1] - 0) * (point2[1] - 0));

    return dist1 < dist2;
  }

public:
  std::vector<int> intersection(std::vector<int> &nums1, std::vector<int> &nums2) {
    std::vector<int> intersection;

    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());

    for (auto i = nums1.begin(); i < nums1.end(); i++) {
      for (auto j = nums2.begin(); j < nums2.end(); j++) {
        if (*i == *j) {
          if (!std::binary_search(intersection.begin(), intersection.end(), *i)) {
            intersection.push_back(*i);
          }
        }
      }
    }

    return intersection;
  }

  std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>> &points, int k) {
    std::vector<std::vector<int>> closest;

    std::sort(points.begin(), points.end(), closer);

    for (auto i = 0; i < k; i++) {
      closest.push_back(points[i]);
    }

    return points;
  }

  int maxScore(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end(), std::greater<int>());
    int score = 0;

    std::vector<long long> prefixes;

    prefixes.push_back(nums[0]);
    for (size_t i = 1; i < nums.size(); i++) {
      prefixes.push_back(prefixes[i - 1] + nums[i]);
    }

    for (auto i = prefixes.begin(); i < prefixes.end(); i++) {
      if (*i > 0) {
        score++;
      }
    }
    return score;
  }

  int minProcessingTime(std::vector<int> &processorTime, std::vector<int> &tasks) {
    std::sort(processorTime.begin(), processorTime.end(), std::greater<int>());
    std::sort(tasks.begin(), tasks.end());

    int maxTimePerCoreCurr = 0;
    auto processorTimeIt = 0;

    for (size_t i = 0; i < tasks.size(); i++) {
      if (i % 4 == 0 && i != 0) {
        processorTimeIt++;
      }
      int processorTimeCalc = processorTime[processorTimeIt] + tasks[i];
      if (processorTimeCalc > maxTimePerCoreCurr) {
        maxTimePerCoreCurr = processorTimeCalc;
      }
    }
    return maxTimePerCoreCurr;
  }

  int minimumPushes(std::string word) {
    std::sort(word.begin(), word.end());
    std::vector<int> letterOccurances;

    char currChar = '\0';
    int currCharCounter = 0;

    for (char c : word) {
      if (currChar == '\0') {
        currChar = c;
        currCharCounter++;
        continue;
      }

      if (currChar != c) {
        letterOccurances.push_back(currCharCounter);
        currChar = c;
        currCharCounter = 0;
      }

      currCharCounter++;
    }

    letterOccurances.push_back(currCharCounter);

    std::sort(letterOccurances.begin(), letterOccurances.end(), std::greater<int>());

    int result = 0;
    int keyPresses = 0;

    for (size_t i = 0; i < letterOccurances.size(); i++) {
      if (i % 9 == 0) {
        keyPresses++;
      }

      result += letterOccurances[i] * keyPresses;
    }

    return result;
  }

  long long largestPerimeter(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end(), std::greater<int>());

    long long currSum = 0;
    for (size_t i = 0; i < nums.size() - 2; i++) {
      for (size_t j = i + 1; j < nums.size(); j++) {
        currSum += nums[j];
      }
      if (nums[i] < currSum) {
        return currSum + nums[i];
      }
      currSum = 0;
    }
    return -1;
  }
};
