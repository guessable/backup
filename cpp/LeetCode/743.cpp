#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
   void dijkstra(vector<vector<pair<int, int>>>& adjList, vector<int>& distance,
                 int begin) {
      int n = adjList.size();
      vector<int> visited(n, 0);
      visited[begin] = 1;
      for(int i = 0; i < n; ++i) {
         int MIN = INT32_MAX, next = -1;
         for(int j = 0; j < n; ++j) {
            if(!visited[j] && distance[j] < MIN) {
               MIN = distance[j];
               next = j;
            }
         }
         if(next == -1) {
            return ;
         }
         visited[next] = 1;
         for(auto node : adjList[next]) {
            if(distance[node.first] > node.second + distance[next]) {
               distance[node.first] = node.second + distance[next];
            }
         }
      }
   }
   int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>> {});
      for(auto time : times) {
         adj[time[0] - 1].push_back(pair<int, int> {time[1] - 1, time[2]});
      }
      vector<int> distance(n, INT32_MAX);
      distance[k - 1] = 0;
      for(auto node : adj[k - 1]) {
         distance[node.first] = node.second;
      }
      dijkstra(adj, distance, k - 1);
      int ans = *max_element(distance.begin(), distance.end());
      return ans == INT32_MAX ? -1 : ans;
   }
};

int main() {
   vector<vector<int>> times{{1, 2, 1}};
   Solution solution;
   int ans = solution.networkDelayTime(times, 2, 1);
   cout << ans << endl;
}
