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
   ListNode* partition(ListNode* head, int x) {
      ListNode* dummyLeft = new ListNode(0);
      ListNode* dummyRight = new ListNode(0);
      ListNode* headLeft = dummyLeft;
      ListNode* headRight = dummyRight;

      while(head != nullptr) {
         if(head->val < x) {
            headLeft->next = head;
            headLeft = headLeft->next;
         } else {
            headRight->next = head;
            headRight = headRight->next;
         }

         head = head->next;
      }

      headRight->next = nullptr;

      headLeft->next = dummyRight->next;
      return dummyLeft->next;
   }
};
