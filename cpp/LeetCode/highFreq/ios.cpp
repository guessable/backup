#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void input1(vector<vector<int>>& ans) {
   /*
    * 类似 [[1,22],[3,45],[5,6]] 的输入(包括括号)
    */
   cin.get();
   while(cin) {
      char ch = cin.get();
      if(ch == '[') {
         vector<int> part;
         int num = 0;
         char temp = '0';
         while(temp != ']') {
            cin >> num >> temp;
            part.push_back(num);
         }
         ans.push_back(part);
      }
      if(ch == '\n') {
         break;
      }
   }
}

void input2(vector<vector<int>>& ans) {
   /*
    * eg. [[12,3],
    * 		[4,5]]
    */
   cin.get();
   while(cin) {
      char flag;
      while(cin) {
         char ch = cin.get();
         if(ch == '[') {
            vector<int> part;
            int num = 0;
            char temp = '0';
            while(temp != ']') {
               cin >> num >> temp;
               part.push_back(num);
            }
            ans.push_back(part);
         }
         if(ch == '\n') {
            break;
         }
         flag = ch;
      }
      if(flag == ']') {
         break;
      }
   }
}

void input3(vector<vector<int>>& nums) {
   int n;
   cin >> n;
   // cin.get();
   for(int i = 0; i < n + 1; ++i) {
      while(cin) {
         char ch = cin.get();
         if(ch == '[') {
            vector<int> part;
            int num = 0;
            char c = '0';
            while(c != ']') {
               cin >> num >> c;
               part.push_back(num);
            }
            nums.push_back(part);
         }
         if(ch == '\n') {
            break;
         }
      }
   }
}

int main() {
   auto cmp = [](vector<int>& a, vector<int>& b) {
      return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
   };
   vector<vector<int>>nums;
   input2(nums);
   sort(nums.begin(), nums.end(), cmp);
   for(auto vec : nums) {
      for(int num : vec) {
         cout << num << " ";
      }
      cout << endl;
   }
}
