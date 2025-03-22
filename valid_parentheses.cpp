#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  unordered_map<char, char> uma = {{'}' , '{'}, {']' , '['}, {')' , '('}};

  bool isValid(string s) {
    vector<char> last_type;

    for (auto c : s) {
      switch (c) {
        case '}':
        case ']':
        case ')':
          if (!last_type.empty() && last_type.back() == uma[c] ) last_type.pop_back();
          else return false; break;
        default :
          last_type.push_back(c);
      }
    };
    if (last_type.empty()) return true;
    return false;
  }
};


int main() {
  Solution c;
  cout << c.isValid("()()()") << c.isValid("[]{()}") << c.isValid("[)");
  return 0;
}
