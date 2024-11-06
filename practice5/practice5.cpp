#include <cstddef>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <vector>
class Solution {
public:
  int maxDepth(std::string s) {
    int maxDepth = 0;
    int currDepth = 0;

    for (size_t i = 0; i < s.length(); i++) {
      switch (s[i]) {
      case '(':
        currDepth++;
        break;
      case ')':
        if (currDepth > maxDepth) {
          maxDepth = currDepth;
        }
        currDepth--;
        break;
      }
    }

    return maxDepth;
  }

  int findTheWinner(int n, int k) {
    std::queue<int> friends;

    for (int i = 1; i <= n; i++) {
      friends.push(i);
    }

    int currCounter = 1;
    while (friends.size() > 1) {
      if (currCounter < k) {
        friends.push(friends.front());
      }
      if (currCounter == k) {
        currCounter = 0;
      }
      friends.pop();
      currCounter++;
    }
    return friends.back();
  }

  int minOperations(std::vector<std::string> &logs) {
    int currOperations = 0;
    for (size_t i = 0; i < logs.size(); i++) {
      if (logs[i] == "../") {
        currOperations = currOperations == 0 ? 0 : currOperations - 1;
      } else if (logs[i] == "./") {
      } else {
        currOperations += 1;
      }
    }
    return currOperations;
  }
};

class MinStack {
public:
  MinStack() {}

  void push(int val) {}

  void pop() {}

  int top() {}

  int getMin() {}
};
