#include <bits/stdc++.h>
using namespace std;

/*
  Time:  O(n!)
  Space: O(n!)
*/
vector<string> permutation(string s) {
  vector<string> res;
  if(s.size() == 2) {
    res.push_back(s);
    string aux;
    aux.push_back(s[1]);
    aux.push_back(s[0]);
    res.push_back(aux);
    return res;
  }
  vector<string> vAux;

  for (int i = 0; i < s.size(); ++i) {
    string aux = "";
        
    for (int j = 0; j < s.size(); ++j) 
      if( i != j ) aux = aux + s[j];
    vAux.clear();
    vAux = permutation(aux);
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