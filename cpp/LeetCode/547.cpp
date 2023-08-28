#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
   int findRoot(vector<int>& root, int a) {
      int aRoot = root[a];

      while(aRoot != root[aRoot]) {
         aRoot = root[aRoot];
      }

      return aRoot;
   }

   void merge(vector<int>& root, int a, int b) {
      int aRoot = findRoot(root, a);
      int bRoot = findRoot(root, b);
      root[aRoot] = bRoot;
   }

   int findCircleNum(vector<vector<int>>& isConnected) {
      int n = isConnected.size();
      vector<int> root(n, 0);
      map<int, int> tab;

      for(int i = 0; i < n; i++) {
         root[i] = i;
      }

      for(int i = 0; i < n; i++) {
         for(int j = n - 1; j > i; j--) {
            if(isConnected[i][j]) {
               merge(root, i, j);
            }
         }
      }

      for(int i = 0; i < n; i++) {
         int iRoot = findRoot(root, i);
         tab[iRoot] = 1;
         cout << root[i] << endl;
      }

      return tab.size();

   }
};

int main() {
   Solution solution;
   vector<vector<int>> isConnected{{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}};
   int ans = solution.findCircleNum(isConnected);
   cout << ans << endl;
}
