/*
 * 单源最短路径
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 邻接矩阵
void dijkstraMatrix (vector<vector<int>>& graph, vector<int>& distance,
                     int begin, int end) {
   int n = graph.size();
   vector<int> visited(n, 0);
   visited[begin] = 1;

   for(int i = 0; i < n; ++i) {
      int MIN = INT32_MAX;
      int next = -1;
      for(int j = 0; j < n; ++j) {
         if(!visited[j] && distance[j] < MIN) {
            MIN = distance[j];
            next = j;
         }
      }
      if(next == -1 || next == end) {
         return ;
      }
      visited[next] = 1;
      for(int k = 0; k < n; ++k) {
         if(graph[next][k] != INT32_MAX &&
               distance[k] > distance[next] + graph[next][k]) {
            distance[k] = distance[next] + graph[next][k];
         }
      }
   }
}

// 邻接表
void dijkstraList(vector<vector<pair<int, int>>>& adjList,
                  vector<int>& distance, int begin, int end) {
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

// 堆优化
void dijkstraHeap(vector<vector<pair<int, int>>>& adj,
                  vector<int>& distance, int begin) {
   distance[begin] = 0;
   auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
      return a.second > b.second;
   };
   priority_queue <pair<int, int>,
                  vector<pair<int, int>>, decltype(cmp)> heap(cmp);
   heap.push(pair<int, int> {begin, 0});
   while(!heap.empty()) {
      auto cur = heap.top();
      heap.pop();
      for(auto node : adj[cur.first]) {
         if(distance[node.first] > distance[cur.first] + node.second) {
            distance[node.first] = distance[cur.first] + node.second;
            heap.push(pair<int, int> {node.first, distance[node.first]});
         }
      }
   }
}

int main() {
   vector<vector<int>> graph{{0, 1, 4, 5},
      {INT32_MAX, 0, 1, 3},
      {INT32_MAX, INT32_MAX, 0, 7},
      {INT32_MAX, INT32_MAX, INT32_MAX, 0}};
   int begin = 2, end = 3;
   vector<int> distance = graph[begin];
   dijkstraMatrix(graph, distance, begin, end);
   cout << distance[end] << endl;
}
