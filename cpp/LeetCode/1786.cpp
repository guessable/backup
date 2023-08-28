#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
   const int max = 9999999;
   void dijkstra(vector<vector<pair<int, int>>>& adj, vector<int>& distance) {
      int n = adj.size();
      vector<int> visited(n, 0);
      visited[n - 1] = 1;
      auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
         return a.second > b.second;
      };
      priority_queue<pair<int, int>,
                     vector<pair<int, int>>, decltype(cmp)> qu(cmp);
      qu.push(pair<int, int> {n - 1, 0});
      while(!qu.empty()) {
         auto cur = qu.top();
         visited[cur.first] = 1;
         qu.pop();
         for(auto node : adj[cur.first]) {
            if(!visited[node.first] &&
                  distance[node.first] > node.second + distance[cur.first]) {
               distance[node.first] = node.second + distance[cur.first];
               qu.push(pair<int, int> {node.first, distance[node.first]});
            }
         }
      }
   }
   int countRestrictedPaths(int n, vector<vector<int>>& edges) {
      vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>> {});
      for(auto edge : edges) {
         adj[edge[0] - 1].push_back(pair<int, int> {edge[1] - 1, edge[2]});
         adj[edge[1] - 1].push_back(pair<int, int> {edge[0] - 1, edge[2]});
      }
      vector<int> distance(n, max);
      dijkstra(adj, distance);
   }
};
