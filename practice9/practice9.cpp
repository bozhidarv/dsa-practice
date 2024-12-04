#include <cstddef>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
class Solution {
public:
  bool buddyStrings(std::string s, std::string goal) {
    if (s.length() != goal.length()) {
      return false;
    }

    if (s == goal) {
      std::unordered_map<char, size_t> map;

      for (size_t i = 0; i < s.length(); i++) {
        map[s[i]] = i;
      }

      return map.size() < s.length();
    }

    std::vector<size_t> diff;

    for (size_t i = 0; i < s.length(); i++) {
      if (s[i] != goal[i]) {
        diff.push_back(i);
      }
    }

    return diff.size() == 2 && s[diff[0]] == goal[diff[1]] && s[diff[1]] == goal[diff[0]];
  }

  int findLHS(std::vector<int> &nums) {
    std::unordered_map<int, int> map;

    for (int num : nums) {
      map[num]++;
    }

    int maxRes = 0;

    for (const auto &pair : map) {
      if (map.find(pair.first + 1) != map.end()) {
        maxRes = std::max(maxRes, pair.second + map[pair.first + 1]);
      }
    }

    return maxRes;
  }

  std::vector<std::string> findWords(std::vector<std::string> &words) {
    std::unordered_map<char, int> rows = {{'q', 1}, {'w', 1}, {'e', 1}, {'r', 1}, {'t', 1},
        {'y', 1}, {'u', 1}, {'i', 1}, {'o', 1}, {'p', 1}, {'a', 2}, {'s', 2}, {'d', 2}, {'f', 2},
        {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'l', 2}, {'z', 3}, {'x', 3}, {'c', 3}, {'v', 3},
        {'b', 3}, {'n', 3}, {'m', 3}};

    std::vector<std::string> oneRowWords;

    for (const std::string &word : words) {
      int row = rows[std::tolower(word[0])];

      for (size_t i = 1; i < word.length(); i++) {
        if (rows[std::tolower(word[i])] != row) {
          row = -1;
          break;
        }
      }
      if (row != -1) {
        oneRowWords.push_back(word);
      }
    }

    return oneRowWords;
  }
};
