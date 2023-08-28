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
   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* dummyHead = new ListNode(0);
      ListNode* head = dummyHead;
      int add = 0;

      while(l1 != nullptr || l2 != nullptr) {
         int val1 = 0;
         int val2 = 0;

         if(l1) {
            val1 = l1->val;
         }

         if(l2) {
            val2 = l2->val;
         }

         int temp = val1 + val2 + add;
         int val = 0;
         temp >= 10 ? val = temp - 10 : val = temp;
         add = temp / 10;

         ListNode* node = new ListNode(val);
         dummyHead->next = node;
         dummyHead = dummyHead->next;

         if(l1) {
            l1 = l1->next;
         }

         if(l2) {
            l2 = l2->next;
         }
      }

      if(add == 1) {
         ListNode* node = new ListNode(1);
         dummyHead->next = node;
         dummyHead = dummyHead->next;
      }

      return head->next;
   }
};
