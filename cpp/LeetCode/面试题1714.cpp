#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
   vector<int> smallestK(vector<int>& arr, int k) {

      if(k == 0) {
         return vector<int> {};
      }

      int n = arr.size();

      priority_queue<int> qe;

      for(int i = 0; i < n; i++) {
         qe.push(arr[i]);
         int size = qe.size();

         if(size > k) {
            qe.pop();
         }
      }

      vector<int> result(k, 0);

      for(int i = 0; i < k; i++) {
         result[k - i - 1] = qe.top();
         qe.pop();
      }

      return result;
   }
};

int main() {
   Solution solution;
   vector<int> arr{1, 2};
   auto ans = solution.smallestK(arr, 2);

   for(int num : ans) {
      cout << num << endl;
   }
}
