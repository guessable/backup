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
   ListNode* oddEvenList(ListNode* head) {
      if(head == nullptr || head->next == nullptr) {
         return head;
      }
      ListNode* dummyHead1 = head;
      ListNode* dummyHead2 = head->next;
      ListNode* first = dummyHead1;
      ListNode* second = dummyHead2;

      while(first->next != nullptr && first->next->next != nullptr) {
         first->next = first->next->next;
         first = first->next;
         second->next = second->next->next;
         second = second->next;
      }

      first->next = dummyHead2;
      return dummyHead1;
   }
};
