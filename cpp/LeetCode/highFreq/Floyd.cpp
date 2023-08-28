#include <iostream>
#include <vector>

using namespace std;

/*
 * A，B两个节点之间的最短路径只有两种可能
 * 1. A直达B
 * 2. A经过一些节点到达B
 * 对于其他节点X，检查dis(XA) + dis(XB) < dis(AB),
 * 成立则设置 dis(AB) = dis(XA) + dis(XB),
 * 遍历完节点，dis(AB) 就是最短路径.
 */

void floyd(vector<vector<int>>& graph) {
   int n = graph.size();
   for(int k = 0; k < n; ++k) { //开始不允许中转，然后允许一个，两个...节点中转
      for(int i = 0; i < n; ++i) {
         for(int j = 0; j < n; ++j) {
            if(graph[i][j] > graph[i][k] + graph[k][j]) {
               graph[i][j] = graph[i][k] + graph[k][j];
            }
         }
      }
   }
}

int main() {
   const int max = 9999999;
   vector<vector<int>> graph{{0, 12, max, max, max, 16, 14},
      {12, 0, 10, max, max, 7, max},
      {max, 10, 0, 3, 5, 6, max},
      {max, max, 3, 0, 4, max, max},
      {max, max, 5, 4, 0, 2, 8},
      {16, 7, 6, max, 2, 0, 9},
      {14, max, max, max, 8, 9, 0}};
   floyd(graph);
   int n = graph.size();
   for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
         cout << graph[i][j] << " ";
      }
      cout << endl;
   }
}
