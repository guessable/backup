#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
   vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
   vector<vector<int>>& secondList) {
      int m = firstList.size(), n = secondList.size();
      int i = 0, j = 0;
      vector<vector<int>> ans;

      while(i < m && j < n) {
         int left = max(firstList[i][0], secondList[j][0]);
         int right = min(firstList[i][1], secondList[j][1]);
         if(left <= right) {
            ans.push_back(vector<int> {left, right});
         }

         if(firstList[i][1] > secondList[j][1]) {
            ++j;
         } else {
            ++i;
         }
      }

      return ans;
   }
};
