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
   ListNode* mergeKLists(vector<ListNode*>& lists) {
      if(lists.empty()) {
         return nullptr;
      }
      int n = lists.size();
      return merge(lists, 0, n - 1);
   }

   ListNode* merge(vector<ListNode*>& lists, int left, int right) {
      if(left >= right) {
         return lists[left];
      }

      int mid = (left + right) / 2;
      ListNode* head1 = merge(lists, left, mid);
      ListNode* head2 = merge(lists, mid + 1, right);

      ListNode* dummyHead = new ListNode(0);
      ListNode* pre = dummyHead;

      while(head1 != nullptr && head2 != nullptr) {
         if(head1->val <= head2->val) {
            pre->next = head1;
            head1 = head1->next;
         } else {
            pre->next = head2;
            head2 = head2->next;
         }
         pre = pre->next;
      }
      pre->next = head1 == nullptr ? head2 : head1;
      return dummyHead->next;
   }
};
