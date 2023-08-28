#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
   int computeArea(int ax1, int ay1, int ax2, int ay2,
                   int bx1, int by1, int bx2, int by2) {

      int area1 = (ay2 - ay1) * (ax2 - ax1);
      int area2 = (by2 - by1) * (bx2 - bx1);
      if(bx1 >= ax2 || bx2 <= ax1 || by1 >= ay2 || by2 <= ay1) {
         return area1 + area2;
      }

      int dx = min(ax2, bx2) - max(ax1, bx1);
      int dy = min(ay2, by2) - max(ay1, by1);

      return area1 + area2 - dx * dy;
   }
};

int main() {
   Solution solution;
   int ans = solution.computeArea(-2, -2, 2, 2, -2, -2, 2, 2);
   cout << ans << endl;
}
