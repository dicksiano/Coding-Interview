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
*/
vector<string> perm2(string s) {
    vector<string> res;
    res.push_back(s);
    reverse(s.begin(), s.end());
    res.push_back(s);
    return res;
}

/*
  Time:  O(n n!)
  Space: O(n!)
*/
vector<string> permutation(string s) {
  if(s.size() == 2) return perm2(s);  // Base case
  vector<string> res, vAux;

  for (int i = 0; i < s.size(); ++i) {
    vAux = permutation( removeChar(s, i) );
    for(vector<string>::iterator it = vAux.begin(); it != vAux.end(); it++)
      res.push_back(s[i] + *it);
  }
  return res;
}

int main() {
  string str = "abcd";
  vector<string> res = permutation(str);
  for (int i = 0; i < res.size(); ++i)
    cout << res[i] << endl;
  return 0;
}