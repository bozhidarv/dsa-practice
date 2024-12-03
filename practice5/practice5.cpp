#include <cstddef>
#include <queue>
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

  int findTheWinnerVector(int n, int k) {
    if (n == 1) {
      return n;
    }

    std::vector<int> friends;

    for (int i = 1; i <= n; i++) {
      friends.push_back(i);
    }

    int currCounter = 1;
    auto currIdx = friends.begin();
    while (true) {
      while (currCounter < k) {
        currIdx++;
        if (currIdx == friends.end()) {
          currIdx = friends.begin();
        }
        currCounter++;
      }

      friends.erase(currIdx);
      if (currIdx == friends.end()) {
        currIdx = friends.begin();
      }
      if (friends.size() == 1) {
        return friends[0];
      }
      currCounter = 1;
    }
    return 0;
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

  int totalSteps(std::vector<int> &nums) {
    std::queue<int> origQueue;

    for (size_t i = 0; i < nums.size(); i++) {
      origQueue.push(nums[i]);
    }

    std::queue<int> newQueue;
    bool isDecreasing = false;
    bool isCurrElDecresing = false;
    int noSteps = 0;
    int currNum = 0;
    while (true) {
      while (!origQueue.empty()) {
        currNum = origQueue.front();
        origQueue.pop();
        if (!isCurrElDecresing) {
          newQueue.push(currNum);
        }
        if (currNum > origQueue.front() && !origQueue.empty()) {
          isCurrElDecresing = true;
          if (!isDecreasing) {
            isDecreasing = true;
          }
        } else {
          isCurrElDecresing = false;
        }
      }
      if (!isDecreasing) {
        return noSteps;
      }

      noSteps++;
      origQueue = newQueue;
      newQueue = std::queue<int>();
      isDecreasing = false;
      isCurrElDecresing = false;
    }

    return 0;
  }
};

struct ListNode {
  int val;
  ListNode *next;
};

class MinStack {
  int min;
  ListNode *head;
  ListNode *mins;

public:
  MinStack() {
    head = nullptr;
    mins = nullptr;
  }

  void push(int val) {
    if (head == nullptr || val <= mins->val) {
      mins = new ListNode{val, mins};
    }
    head = new ListNode{val, head};
  }

  void pop() {
    if (head == nullptr) {
      return;
    }

    if (head->val == mins->val) {
      ListNode *tempMins = mins->next;
      delete mins;
      mins = tempMins;
    }

    ListNode *tempHead = head->next;
    delete head;
    head = tempHead;

    if (mins == nullptr && head != nullptr) {
      mins = new ListNode{head->val, nullptr};
    }
  }

  int top() { return head->val; }

  int getMin() { return mins->val; }
};
