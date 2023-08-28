#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
   int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int n = gas.size();
      int minVal = INT32_MAX, minIndex = 0, sum = 0;
      for(int i = 0; i < n; ++i) {
         sum += gas[i] - cost[i];
         if(sum < minVal) {
            minVal = sum;
            minIndex = i;
         }
      }

      return sum < 0 ? -1 : (minIndex + 1);
   }
};
