#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
   bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      int count = 0;
      vector<vector<int>> adj(numCourses, vector<int> {});
      vector<int> degree(numCourses, 0);
      for(auto prerequisite : prerequisites) {
         adj[prerequisite[0]].push_back(prerequisite[1]);
         ++degree[prerequisite[1]];
      }
      queue<int> qu;
      for(int i = 0; i < numCourses; ++i) {
         if(!degree[i]) {
            qu.push(i);
         }
      }
      while(!qu.empty()) {
         int cur = qu.front();
         qu.pop();
         ++count;

         for(int num : adj[cur]) {
            if(--degree[num] == 0) {
               qu.push(num);
            }
         }
      }

      if(count < numCourses) {
         return false;
      }
      return true;
   }
};

int main() {
   Solution solution;
   vector<vector<int>> nums{{1, 0}};
   bool ans = solution.canFinish(2, nums);
   cout << ans << endl;
}
