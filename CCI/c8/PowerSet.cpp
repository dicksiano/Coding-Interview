#include <bits/stdc++.h>
using namespace std;

/* 
  Time:  O(2^n)
  Space: O(2^n)
*/
vector< vector<int> > powerSet(vector<int> v) {
  vector< vector<int> > ans;
  vector<int> aux;

  for (int i = 0; i < (1 << v.size()); ++i) {
    aux.clear();
    for (int j = 0; j < v.size(); ++j) 
      if( (1 << j) & i) aux.push_back(v[j]);

    ans.push_back(aux); 
  }
  return ans;
}
int main() {
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);

  vector< vector<int> > ans = powerSet(v);
  for (int i = 0; i < ans.size(); ++i) {
    for (int j = 0; j < ans[i].size(); ++j) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}