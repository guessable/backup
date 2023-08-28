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
   ListNode* reverseBetween(ListNode* head, int left, int right) {
      if(left == right) {
         return head;
      }

      ListNode* curLeft = head;
      ListNode* curRight = head;

      for(int i = 0; i < left - 1; ++i) {
         curLeft = curLeft->next;
      }

      for(int i = 0; i < right; ++i) {
         curRight = curRight->next;
      }

      ListNode* pre = curRight->next;
      ListNode* node = reverse(curLeft->next, pre);
      curLeft->next = node;
      return head;

   }

   ListNode* reverse(ListNode* head, ListNode* pre) {
      if(head == nullptr) {
         return nullptr;
      }

      ListNode* cur = head;
      ListNode* next = cur->next;

      while(cur != nullptr && cur->next != nullptr) {
         cur->next = pre;
         pre = cur;
         cur = next;
         next = next -> next;
      }

      cur->next = pre;
      return cur;
   }
};
