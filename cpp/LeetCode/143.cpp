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
   void reorderList(ListNode* head) {
      if(head == nullptr || head->next == nullptr) {
         return ;
      }

      ListNode* slow = head;
      ListNode* fast = head;
      ListNode* pre = nullptr;

      while(fast != nullptr && fast->next != nullptr) {
         pre = slow;
         slow = slow->next;
         fast = fast->next->next;
      }

      pre->next = nullptr;
      ListNode* headB = reverse(slow);
      merge(head, headB);
   }

   ListNode* reverse(ListNode* head) {
      if(head == nullptr || head->next == nullptr) {
         return head;
      }
      ListNode* pre = nullptr;
      ListNode* cur = head;
      ListNode* next = cur->next;

      while(cur != nullptr && cur->next != nullptr) {
         cur->next = pre;
         pre = cur;
         cur = next;
         next = cur->next;
      }

      cur->next = pre;
      return cur;
   }

   void merge(ListNode* headA, ListNode* headB) {
      ListNode* ptrA = headA;
      ListNode* ptrB = headB;

      while(ptrA != nullptr) {
         ListNode* tempA = ptrA->next;
         ptrA->next = ptrB;
         ptrA = tempA;
         if(ptrA != nullptr) {
            ListNode* tempB = ptrB->next;
            ptrB->next = ptrA;
            ptrB = tempB;
         }
      }
   }
};
