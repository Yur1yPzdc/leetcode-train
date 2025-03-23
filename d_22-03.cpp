#include <queue>
#include <vector>
#include<iostream>

using namespace std;


class Solution {
public:
  int del_subgraph_(vector<vector<int>>* edges, vector<bool>* visited) {
    int siz = (*edges).size();
    int v_id, ans;
    for (int i=0; i<siz; i++) {
      if (!(*edges)[i].empty()) { v_id=i; break; }
    }
    queue<int> q;
    vector<int> vis_int;

    (*visited)[v_id]=true;
    vis_int.push_back(v_id);
    q.push(v_id);

    while (!q.empty()) {
      int curr = q.front();
      q.pop();

      for (auto x : (*edges)[curr]) {
        if (!(*visited)[x]) {
          //cout << "qawae" << x<< endl;
          (*visited)[x] = true;
          vis_int.push_back(x);
          q.push(x);
        }
      }
    }

    ans=vis_int.size();
    //cout << "removing "<<ans<<" nodes\n";

    for (int kkk=0; kkk<ans; kkk++) {
      int c = vis_int[kkk];
      auto be=(*edges).begin(), en=(*edges).end();
      for (; en>=be; en--) {
        for (auto x : *(en)) {
          if (x==c) {
            *(en) = {};
            break;
          }
        }
      }
    }

    return ans+1;
  }
  
  int del_subgraph(vector<vector<int>>* edges, vector<bool>* visited) {
    int siz = (*edges).size();
    int v_id, ans;
    for (int i=0; i<siz; i++) {
      if (!(*edges)[i].empty()) { v_id=i; break; }
    }

    bool is_good=true;
    vector<int> vertices_to_see((*edges)[v_id]);
    vertices_to_see.push_back(v_id);

    priority_queue<int> pq;
    for (auto x : vertices_to_see) { pq.push(x); }

    for (auto i : vertices_to_see) {
      vector<int> vertices_to_see_((*edges)[i]);
      vertices_to_see_.push_back(i);
      if (vertices_to_see.size()!=vertices_to_see_.size()) {is_good=false; break;}

      priority_queue<int> pq_;
      for (auto x : vertices_to_see_) { pq.push(x); }
      while (!pq.empty()) {
        int a = pq.top(), a_=pq.top();
        if (a!=a_) { is_good=false; break;}
        pq.pop(); pq_.pop();
      }
    }
    if (!is_good) return del_subgraph_(edges, visited);

    ans=vertices_to_see.size();

    for (int kkk=0; kkk<ans; kkk++) {
      int c = vertices_to_see[kkk];
      auto be=(*edges).begin(), en=(*edges).end();
      for (; en>=be; en--) {
        for (auto x : *(en)) {
          if (x==c) {
            *(en) = {};
            break;
          }
        }
      }
    }

    return ans;
  }
  int countCompleteComponents(int n, vector<vector<int>>& e) {
    vector<vector<int>> edges;
    int saiz = e.size();
    vector<bool> visited(saiz, false);
    
    for (int i=0; i<n; i++) {
      vector<int> s;
      for (auto x : e) {
        if (i==x[0]) s.push_back(x[1]);
        else if (i==x[1]) s.push_back(x[0]);
      }
      edges.push_back(s);
    }
    int ans=0;
    bool is_empty=true;
    for (auto x : edges) if (!x.empty()) { is_empty=false; break;}
    while (!is_empty) {
      is_empty=true;
      //for (auto x : edges) for (auto xx : x) cout << xx;
      //cout << endl;
      ans++;
      n-=del_subgraph(&edges, &visited);
      for (auto x : edges) if (!x.empty()) { is_empty=false; break;}
    }
    return ans+n;
  }
};


int main() {
  Solution sol;
  int cnt=6;
  vector<vector<int>> edgess={{0,1},{0,2},{1,2},{3,4}, {3,5}};
  vector<vector<int>> edges={{0,1},{0,2},{1,2},{3,4}};
  vector<vector<int>> e = {{0,1}};
  cout << sol.countCompleteComponents(cnt, edgess);

  return 0;
}
