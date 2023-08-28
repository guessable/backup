#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
   int val;
   ListNode* next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
   ListNode* rotateRight(ListNode* head, int k) {
      if(k == 0 || head == nullptr) {
         return head;
      }
      int n = 1;
      ListNode* tail = head;
      while(tail != nullptr && tail->next != nullptr) {
         ++n;
         tail = tail->next;
      }
      k %= n;
      if(k == 0) {
         return head;
      }
      ListNode* cur = head;

      for(int i = 1; i < n - k; ++i) {
         cur = cur->next;
      }

      ListNode* newHead = cur->next;
      cur->next = nullptr;
      tail->next = head;
      return newHead;
   }
};
