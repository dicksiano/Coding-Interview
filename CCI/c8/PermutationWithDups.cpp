#include <bits/stdc++.h>
using namespace std;

/*
  (xyz, 1) => xz
*/
string removeChar(string s, int i) {
    string aux = "";
    for (int j = 0; j < s.size(); ++j) 
      if( i != j ) aux = aux + s[j];
    return aux;
}

/*
  xy => {xy, yx}
  xx => {xx}
*/
vector<string> perm2(string s) {
    vector<string> res;
    res.push_back(s);
    reverse(s.begin(), s.end());
    if(s[0] != s[1]) res.push_back(s);
    return res;
}

/*
  Time:  O(n n!)
  Space: O(n!)
*/
vector<string> permutation(string s) {
  if(s.size() == 2) return perm2(s);     // Base case
  vector<string> res, vAux;

  sort( s.begin(), s.end() );           // Sort to make duplicated letter be neighbours
  for (int i = 0; i < s.size(); ++i) {
    if(i == 0 || s[i] != s[i-1]) {      // Check if there are duplicated values
      vAux = permutation( removeChar(s, i) );
      for(vector<string>::iterator it = vAux.begin(); it != vAux.end(); it++)
        res.push_back(s[i] + *it);
    }
  }
  return res;
}

int main() {
  string str = "abcb";
  vector<string> res = permutation(str);
  for (int i = 0; i < res.size(); ++i)
    cout << res[i] << endl;
  return 0;
}