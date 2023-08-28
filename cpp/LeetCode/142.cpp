#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
   int val;
   ListNode* next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
   ListNode* detectCycle(ListNode* head) {
      if(head == nullptr || head->next == nullptr) {
         return nullptr;
      }

      ListNode* fast = head;
      ListNode* slow = head;

      while(fast != nullptr && fast->next != nullptr) {
         slow = slow->next;
         fast = fast->next->next;
         if(fast == slow) {
            break;
         }
      }

      slow = head;

      while(slow != fast && fast != nullptr) {
         slow = slow->next;
         fast = fast->next;
      }

      return fast;
   }
};
