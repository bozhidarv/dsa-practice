/*#include "iterators/iterators.cpp"*/
/*#include "sorts/sorts.cpp"*/
#include "practice8/practice8.cpp"
#include <iostream>
#include <ostream>

void inorderTraversal(TreeNode *root) {
  if (root != nullptr) {
    inorderTraversal(root->left);
    std::cout << root->val << " ";
    inorderTraversal(root->right);
  }
}

int main() {
  Solution s;
  // Input: [{1->4->5},{1->3->4},{2->6}] - std::vector<ListNode*>

  ListNode *l1 = new ListNode(1);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(5);

  ListNode *l2 = new ListNode(1);
  l2->next = new ListNode(3);
  l2->next->next = new ListNode(4);

  ListNode *l3 = new ListNode(2);
  l3->next = new ListNode(6);

  std::vector<ListNode *> lists = {l1, l2, l3};
  // std::vector<ListNode *> lists = {};

  ListNode *result = s.mergeKLists(lists);

  while (result != nullptr) {
    std::cout << result->val << " ";
    result = result->next;
  }
}
