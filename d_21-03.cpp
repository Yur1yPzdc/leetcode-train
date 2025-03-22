#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  bool are_all_in(vector<string>* ing, vector<string>* reqs) {
    for (auto x : (*reqs)) {
      bool x_in_ing = false;
      for (auto y : (*ing)) {
        if (x==y) {
          x_in_ing = true;
          break;
        }
      }
      if (!x_in_ing) {
        return false;
      }
    }
    return true;
  }
  vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supp) {
    vector<string> supplies = supp;
    vector<string> ans, recent;
    vector<bool> reached  (recipes.size(), false);
    bool were_changes_made = true;
    while (were_changes_made) {
      recent={};
      were_changes_made=false;
      for (int i=0; i < recipes.size(); i++) {
        if (reached[i]) continue;
        vector<string>* its_ingr = &(ingredients[i]);
        vector<string>* stuff=&(supplies);
        string stufff;
        for ( auto i : supplies) stufff+=" " + i;
        bool is_creatable = are_all_in(stuff, its_ingr);
        cout << recipes[i] << " " << stufff << " " << is_creatable << endl;
        if (is_creatable) {
          were_changes_made=true;
          vector<string> that = {recipes[i]};
          reached[i] = true;
          ans.push_back(recipes[i]);
          recent.push_back(recipes[i]);
        }
      }
      for (auto x : recent) {
        supplies.push_back(x);
      }
    }
    return ans;
  }
};



int main() {
  Solution sol;
  vector<string> r = {"bread","sandwich", "burger"};
  vector<vector<string>> i = {{"yeast", "flour"}, {"bread","meat"}, {"sandwich","meat","bread"}};
  vector<string> s = {"yeast","flour","meat"};

  auto a =sol.findAllRecipes(r, i, s); 
  for (auto x : a) {
    cout << x << " " ;
  }
  return 0;
}
