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
   ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
      ListNode* ptrA = headA;
      ListNode* ptrB = headB;

      if(!headA || !headB) {
         return nullptr;
      }

      while(ptrA != ptrB) {
         ptrA == nullptr ? ptrA = headB : ptrA = ptrA->next;
         ptrB == nullptr ? ptrB = headA : ptrB = ptrB->next;
      }

      return ptrA;
   }
};
