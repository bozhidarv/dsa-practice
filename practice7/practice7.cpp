#include <map>
#include <set>
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

class Solution {
  void fillSet(std::set<int> *set, TreeNode *root) {
    if (root == nullptr) {
      return;
    }

    set->insert(root->val);
    fillSet(set, root->right);
    fillSet(set, root->left);
  }

  void insertBst(TreeNode **root, int value) {
    TreeNode **currEl = root;
    while (*currEl) {
      if ((*currEl)->val < value) {
        currEl = &(*currEl)->right;
      } else if (value < (*currEl)->val) {
        currEl = &(*currEl)->left;
      } else {
        return;
      }
    }
    *currEl = new TreeNode(value);
  }

public:
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    TreeNode **curr = &root;
    while (*curr != nullptr) {
      if (val < (*curr)->val) {
        curr = &(*curr)->left;
      } else if ((*curr)->val < val) {
        curr = &(*curr)->right;
      } else {
        return root;
      }
    }

    *curr = new TreeNode(val);
    return root;
  }

  int kthSmallest(TreeNode *root, int k) {
    if (root == nullptr) {
      return -1;
    }

    std::set<int> smallestElements;
    fillSet(&smallestElements, root);

    int counter = -1;
    for (auto &el : smallestElements) {
      counter++;
      if (counter == k - 1) {
        return el;
      }
    }
    return root->val;
  }

  TreeNode *sortedArrayToBST(std::vector<int> &nums) {
    return addElementsRec(nums.begin(), nums.end());
  }

  TreeNode *addElementsRec(
      const std::vector<int>::iterator start, const std::vector<int>::iterator end) {
    size_t sliceSize = end - start;
    if (sliceSize == 0) {
      return nullptr;
    }
    if (sliceSize == 1) {
      return new TreeNode(*start);
    }
    size_t middleIdx = sliceSize / 2;

    TreeNode *root = new TreeNode(*(start + middleIdx));

    root->left = addElementsRec(start, start + middleIdx);
    root->right = addElementsRec(start + middleIdx + 1, end);

    return root;
  }

  int rangeSumBST(TreeNode *root, int low, int high) {
    if (root == nullptr) {
      return 0;
    }

    int sum = 0;

    sum += rangeSumBST(root->left, low, high);
    sum += rangeSumBST(root->right, low, high);

    if (root->val <= high && low <= root->val) {
      sum += root->val;
    }
    return sum;
  }

  int firstUniqChar(std::string s) {
    std::map<size_t, int> chars;
    for (size_t i = 0; i < s.size(); i++) {
      char c = s[i];
      const auto &charLoc = chars.find(c);
      if (charLoc != chars.end()) {
        chars[c] = s.size();
      } else {
        chars[c] = i;
      }
    }

    size_t idx = s.size();
    for (auto it = chars.begin(); it != chars.end(); ++it) {
      if (it->second < idx) {
        idx = it->second;
      }
    }

    return idx == s.size() ? -1 : idx;
  }

  int kthSmallest(std::vector<std::vector<int>> &matrix, int k) {
    std::map<int, int> m;

    for (size_t i = 0; i < matrix.size(); i++) {
      for (size_t j = 0; j < matrix.size(); j++) {
        m[matrix[i][j]]++;
      }
    }

    int i = 1;
    for (const auto &el : m) {
      if (i == k || (i < k && k <= (i + el.second - 1))) {
        return el.first;
      }
      i += el.second;
    }
    return -1;
  }
};

class MyCalendar {
private:
  std::map<int, int> events;

public:
  MyCalendar() {}

  bool book(int startTime, int endTime) {
    auto next = events.lower_bound(startTime);

    if (next != events.end() && next->first < endTime) {
      return false;
    }

    if (next != events.begin()) {
      auto prev = --next;
      if (prev->second > startTime) {
        return false;
      }
    }

    events[startTime] = endTime;
    return true;
  }
};
