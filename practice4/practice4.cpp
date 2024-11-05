struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *removeElements(ListNode *head, int val) {
    ListNode *curr = head;
    ListNode *newHead = head;
    ListNode *prev = nullptr;
    while (curr) {
      if (curr->val == val) {
        if (prev != nullptr) {
          prev->next = curr->next;
        } else {
          newHead = curr->next;
        }
        ListNode *temp = curr->next;
        delete curr;
        curr = temp;
      } else {
        prev = curr;
        curr = curr->next;
      }
    }
    return newHead;
  }

  ListNode *swapNodes(ListNode *head, int k) {
    ListNode *curr1 = head;
    ListNode *curr2 = head;

    int i = 1;
    while (curr1 && i < k) {
      curr1 = curr1->next;
      i++;
    }

    if (i < k) {
      return head;
    }

    ListNode *first = curr1;

    while (curr1->next) {
      curr1 = curr1->next;
      curr2 = curr2->next;
    }

    int temp = first->val;
    first->val = curr2->val;
    curr2->val = temp;
    return head;
  }

  ListNode *partition(ListNode *head, int x) {
    ListNode *greaterListBegin = nullptr;
    ListNode *greaterListEnd = nullptr;

    ListNode *lessListBegin = nullptr;
    ListNode *lessListEnd = nullptr;

    while (head != nullptr) {
      if (head->val > x) {
        if (greaterListBegin == nullptr) {
          greaterListBegin = greaterListEnd = head;
        } else {
          greaterListEnd->next = head;
          greaterListEnd = head;
        }
      } else {
        if (lessListBegin == nullptr) {
          lessListBegin = lessListEnd = head;
        } else {
          lessListEnd->next = head;
          lessListEnd = head;
        }
      }
      head = head->next;
    }
    if (lessListEnd) {
      lessListEnd->next = greaterListBegin;
    }
    if (greaterListEnd)
      greaterListEnd->next = nullptr;

    return lessListBegin != nullptr ? lessListBegin : greaterListBegin;
  }

  ListNode *doubleIt(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *curr = head;

    while (curr != nullptr) {
      ListNode *nextNode = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nextNode;
    }

    head = prev;

    ListNode *node = head;
    int carry = 0;

    while (node != nullptr) {
      int doubledValue = node->val * 2 + carry;
      node->val = doubledValue % 10;
      carry = doubledValue / 10;

      if (node->next == nullptr && carry > 0) {
        node->next = new ListNode(carry);
        carry = 0;
        if (carry < 10) {
          break;
        }
      }

      node = node->next;
    }

    prev = nullptr;
    curr = head;

    while (curr != nullptr) {
      ListNode *nextNode = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nextNode;
    }

    return prev;
  }
};
