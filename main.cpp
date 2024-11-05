/*#include "iterators/iterators.cpp"*/
/*#include "sorts/sorts.cpp"*/
#include "practice4/practice4.cpp"
#include <iostream>

int main() {
  Solution solutions;

  ListNode *node1 = new ListNode(5, nullptr);
  /* ListNode *node2 = new ListNode(2); */
  /* ListNode *node3 = new ListNode(9); */
  /* node1->next = node2; */
  /* node2->next = node3; */

  ListNode *curr = solutions.doubleM(node1);

  while (curr != nullptr) {
    std::cout << curr->val << std::endl;
    curr = curr->next;
  }
}
