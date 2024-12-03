#include <algorithm>
#include <cmath>
#include <functional>
#include <queue>
#include <string>
#include <vector>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  bool greaterListNode(const ListNode *&node1, const ListNode *&node2) {
    if (node2 == nullptr || (node1 == nullptr && node2 == nullptr)) {
      return false;
    }

    if (node1 == nullptr) {
      return true;
    }
    return node1->val > node2->val;
  }

public:
  int lastStoneWeight(std::vector<int> &stones) {
    std::make_heap(stones.begin(), stones.end());

    int largestStone, secondLargestStone;
    while (stones.size() > 1) {
      largestStone = stones[0];
      std::pop_heap(stones.begin(), stones.end());
      stones.pop_back();

      secondLargestStone = stones[0];
      std::pop_heap(stones.begin(), stones.end());
      stones.pop_back();

      int currStoneWeight = secondLargestStone;

      if (largestStone != secondLargestStone) {
        currStoneWeight = largestStone - secondLargestStone;
        stones.push_back(currStoneWeight);
        std::push_heap(stones.begin(), stones.end());
      }

      if (stones.size() == 0) {
        return 0;
      }
    }
    return stones[0];
  }

  std::vector<std::string> findRelativeRanks(std::vector<int> &score) {
    std::priority_queue<std::pair<int, size_t>> sortedScores;

    for (size_t i = 0; i < score.size(); i++) {
      sortedScores.push(std::pair(score[i], i));
    }

    std::vector<std::string> strs(score.size());

    int p = 1;
    while (!sortedScores.empty()) {
      if (p == 1) {
        strs[sortedScores.top().second] = "Gold Medal";
      } else if (p == 2) {
        strs[sortedScores.top().second] = "Silver Medal";

      } else if (p == 3) {
        strs[sortedScores.top().second] = "Bronze Medal";
      } else {
        strs[sortedScores.top().second] = std::to_string(p);
      }
      p++;
      sortedScores.pop();
    }
    return strs;
  }

  long long pickGifts(std::vector<int> &gifts, int k) {

    std::priority_queue<int> pq(gifts.begin(), gifts.end());

    int it = 0;
    while (it < k) {
      int largestGiftPile = pq.top();
      pq.pop();
      pq.push(std::floor(std::sqrt(largestGiftPile)));
      it++;
    }

    long long numberOfGifts = 0;
    while (!pq.empty()) {
      numberOfGifts += pq.top();
      pq.pop();
    }

    return numberOfGifts;
  }

  ListNode *mergeKLists(std::vector<ListNode *> &lists) {
    std::priority_queue<std::pair<int, ListNode *>, std::vector<std::pair<int, ListNode *>>,
        std::greater<std::pair<int, ListNode *>>>
        pq;
    for (const auto &list : lists) {
      ListNode *currEl = list;
      while (currEl != nullptr) {
        pq.push(std::pair(currEl->val, currEl));
        currEl = currEl->next;
      }
    }

    ListNode *head = nullptr;
    ListNode *currNode = nullptr;

    while (!pq.empty()) {
      std::pair<int, ListNode *> currEl = pq.top();
      pq.pop();

      if (currNode == nullptr) {
        head = currEl.second;
        currNode = head;
      } else {
        currNode->next = currEl.second;
        currNode = currEl.second;
      }
    }
    if (currNode && currNode->next) {
      currNode->next = nullptr;
    }
    return head;
  }

  int leastInterval(std::vector<char> &tasks, int n) {
    std::vector<int> taskCount(26, 0);
    for (char task : tasks) {
      taskCount[task - 'A']++;
    }

    std::priority_queue<int> pq(taskCount.begin(), taskCount.end());

    int maxFreq = pq.top();
    pq.pop();
    int idleSlots = (maxFreq - 1) * n;

    while (!pq.empty()) {
      idleSlots -= std::min(pq.top(), maxFreq - 1);
      pq.pop();
    }

    idleSlots = std::max(0, idleSlots);
    return tasks.size() + idleSlots;
  }
};

class KthLargest {

  std::priority_queue<int, std::vector<int>, std::greater<int>> elements;
  int k;

public:
  KthLargest(int k, std::vector<int> &nums) {
    elements =
        std::priority_queue<int, std::vector<int>, std::greater<int>>(nums.begin(), nums.end());
    this->k = k;
  }

  int add(int val) {
    elements.push(val);
    while (elements.size() > (size_t)k) {
      elements.pop();
    }
    return elements.top();
  }
};
