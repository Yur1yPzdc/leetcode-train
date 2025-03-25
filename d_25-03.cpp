#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
    vector<bool> is_occupied_x(2*n-1,false);
    vector<bool> is_occupied_y(2*n-1,false);
    for (auto x : rectangles) {
      int a=2*x[0],b=2*x[2], aa=2*x[1], bb=2*x[3];
      for (int i=a+1; i<b;i++) {
        is_occupied_x[i-1]=true;
      } 
      for (int i=aa+1; i<bb;i++) {
        is_occupied_y[i-1]=true;
      } 
    }
    int ansx=0, ansy=0;
    for (int x=1; x<2*n-2;x++) {
      if (!is_occupied_x[x] && is_occupied_x[x+1] && is_occupied_x[x-1]) ansx++;
      if (!is_occupied_y[x] && is_occupied_y[x+1] && is_occupied_y[x-1]) ansy++;
    }
    if (ansx>=2 || ansy>=2){ cout <<"!"; return true; }
    return false;
  }
};

int main() {
  Solution s;
  vector<vector<int>> v = {{1,0,5,2},{0,2,2,4},{3,2,5,3},{0,4,4,5}};

  cout << s.checkValidCuts(5, v);

  return 0;
}
