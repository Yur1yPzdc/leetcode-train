#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
  int MaxDepth(int x,int parent){
    int mx = 0;
    for(int  i = 0;i < graph[x].size();i++)
      if(graph[x][i]!=parent){
          mx = max(MaxDepth(graph[x][i],x),mx);
      }
        return mx + 1;
  }
  int dist(vector<string>* recipes, vector<vector<string>>* ing, int which) {
    queue<string> a;

    unordered_map<string, int> as;
    for (int i=0; i<(*recipes).size(); i++) as[(*recipes)[i]] = i;

    vector<bool> vis((*ing).size(), false);
    int depth=1;
    vis[which] = true;

    a.push((*recipes)[which]);

    depth+=(*recipes)[which].size()+1;

    while (!a.empty()) {
      string curr = a.front();
      a.pop();
      depth--;

      if (as.count(curr)==0)  continue;

      int cind = as[curr];
      depth+=(*recipes)[cind].size()+1;

      for (auto x : (*ing)[cind]) {
        if (!vis[cind]) {
          vis[cind] = true;
          a.push(curr);
        }
      }
    }
  }
  vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    vector<string> ans;
    queue<string> a;
    bool were_changes_made = false;
    while (were_changes_made) {
      for (int i=0; recipes[i] != recipes.back(); i++) {
        vector<string> its_ingr = ingredients[i];
        bool are_any_missing = false;
        for (auto i : supplies) {
          for (int ii=0; its_ingr[ii]!=its_ingr.back(); ii++ ) if (its_ingr[ii]==i) its_ingr.erase(its_ingr.begin()+ii);
        }
      }
    }
  }
};
