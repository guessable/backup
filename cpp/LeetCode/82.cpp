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
   ListNode* deleteDuplicates(ListNode* head) {
      if(head == nullptr || head->next == nullptr) {
         return head;
      }

      ListNode* dummyHead = new ListNode(0);
      dummyHead->next = head;
      ListNode* pre = dummyHead;
      ListNode* first = head;
      ListNode* second = head->next;

      while(second != nullptr) {
         if(first->val != second->val) {
            pre = first;
            first = second;
            second = second->next;
         } else {
            while(second != nullptr && second->val == first->val) {
               second = second->next;
            }

            first = second;

            if(second != nullptr) {
               second = second->next;
            }

            pre->next = first;
         }
      }

      return dummyHead->next;
   }
};
