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
   ListNode* reverseKGroup(ListNode* head, int k) {
      ListNode* first = head;
      ListNode* second = head;
      for(int i = 0; i < k; ++i) {
         if(second == nullptr) {
            return head;
         }
         second = second->next;
      }
      ListNode* newHead = reverse(first, second);
      first->next = reverseKGroup(second, k);
      return newHead;
   }

   ListNode* reverse(ListNode* head, ListNode* tail) {
      ListNode* pre = nullptr;
      ListNode* cur = head;
      ListNode* next = cur;
      while(cur != tail) {
         next = cur->next;
         cur->next = pre;
         pre = cur;
         cur = next;
      }
      return pre;
   }
};
