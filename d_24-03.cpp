#include <iostream>
#include <vector>

using namespace std;
class Solution {
private:
  void merge(vector<vector<int>>* a, int start, int mid, int end){
    int idx_l=start, idx_r=mid+1;

    vector<vector<int>> sec(end-start+1);
    int idx_s=0;

    for (int i=start; i<=end; i++){
      if (idx_l>mid) {
        sec[idx_s] = (*a)[idx_r++];
      } else if (idx_r>end) {
        sec[idx_s] = (*a)[idx_l++];
      } else {
        if ((*a)[idx_l][0]<(*a)[idx_r][0] || ((*a)[idx_l][0]==(*a)[idx_r][0] && (*a)[idx_l][1]<(*a)[idx_r][1])) {
          sec[idx_s] = (*a)[idx_l++];
        } else {
          sec[idx_s] = (*a)[idx_r++];
        }
      }
      idx_s++;
    }
    for (int i=0; i<idx_s; i++) {
      (*a)[start++] = sec[i];
    }
  }

  void m_sort(vector<vector<int>>* a, int start, int end){
    if (start<end) {
      int mid = (end+start)/2;

      m_sort(a,start,mid);
      m_sort(a,mid+1,end);

      merge(a,start,mid,end);
    }
  }
public:
  int countDays(int days, vector<vector<int>>& meetings) {
    int ans=0;
    m_sort(&meetings, 0, meetings.size()-1);

    auto b=meetings.begin(), e=meetings.end();
    int v=0;
    for (;b<e;b++) {
      cout << b->front() << " " << b->back() << " ;";
      if ((b->front() <= v) && (b->back() > v)) {
        v = b->back();
      } else if (b->front() > v) {
        ans+=b->front()-v-1;
        v=b->back();
      }
      cout << v << "|" ;
    }
    cout << ans << " ";
    
    return ans+days-v;
  }

int main() {
  Solution s;
  vector<vector<int>> v={{2,4},{1,3}};
  vector<vector<int>> vv = {{6,11},{7,13},{8,9},{5,8},{3,13},{11,13},{1,3},{5,10},{8,13},{3,9}};
  vector<vector<int>> vvv = {{5,7},{1,3},{9,10}};
  vector<vector<int>> vvvv = {{3,49},{23,44},{21,56},{26,55},{23,52},{2,9},{1,48},{3,31}}; // 57
  cout << s.countDays(57,vvvv);

  return 0;
}
