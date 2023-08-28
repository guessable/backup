#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *sortList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *pre = slow;
    while (fast != nullptr && fast->next != nullptr) {
      pre = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    pre->next = nullptr;
    ListNode *leftNode = sortList(head);
    ListNode *rightNode = sortList(slow);

    ListNode *dummyHead = new ListNode(0);
    ListNode *newhead = dummyHead;
    while (leftNode != nullptr || rightNode != nullptr) {
      if (leftNode == nullptr) {
        newhead->next = rightNode;
        rightNode = rightNode->next;
      } else if (rightNode == nullptr) {
        newhead->next = leftNode;
        leftNode = leftNode->next;
      } else if (rightNode->val < leftNode->val) {
        newhead->next = rightNode;
        rightNode = rightNode->next;
      } else {
        newhead->next = leftNode;
        leftNode = leftNode->next;
      }
      newhead = newhead->next;
    }
    return dummyHead->next;
  }
};
