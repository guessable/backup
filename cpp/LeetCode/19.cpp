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
   ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* left = head;
      ListNode* right = head;
      for(int i = 0; i < n; ++i) {
         right = right->next;
      }

      if(right == nullptr) {
         return head->next;
      }

      while(right != nullptr && right->next != nullptr) {
         left = left->next;
         right = right->next;
      }

      ListNode* temp = left->next;
      left->next = temp->next;
      delete temp;
      return head;
   }
};
