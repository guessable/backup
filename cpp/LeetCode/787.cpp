#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
   int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      vector<vector<int>> graph(n, vector<int>(n, 0));
      for(auto flight : flights) {
         graph[flight[0]][flight[1]] = flight[2];
      }
      auto cmp = [](vector<int>& a, vector<int>& b) {
         return a[1] > b[1];
      };
      priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> qu(cmp);
      qu.push(vector<int> {src, 0, k + 1});
      while(!qu.empty()) {
         auto cur = qu.top();
         qu.pop();
         int from = cur[0];
         int price = cur[1];
         int k = cur[2];

         if(from == dst) {
            return price;
         }

         if(k > 0) {
            for(int i = 0; i < n; ++i) {
               if(graph[from][i] > 0) {
                  qu.push(vector<int> {i, price + graph[from][i], k - 1});
               }
            }
         }
      }
      return -1;
   }
};

int main() {
   Solution solution;
   vector<vector<int>> edges{{0, 1, 100}, {1, 2, 100}, {0, 2, 500}, {2, 3, 100}};
   int ans = solution.findCheapestPrice(4, edges, 0, 3, 2);
   cout << ans << endl;
}
