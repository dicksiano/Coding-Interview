#include <bits/stdc++.h>
using namespace std;

bool comp(pair<string,string> a, pair<string,string> b) { return a.second < b.second; }

unordered_map<string, vector<string> > fillHashTable(vector<string> v) {
  unordered_map<string, vector<string> > hashTable;
  string aux; vector<string> vaux;

  for (int i = 0; i < v.size(); ++i) {  // M strings
    aux = v[i];
    sort(aux.begin(),aux.end());        // O(n log n)

    if(hashTable.find(aux) == hashTable.end()) { vaux.clear(); vaux.push_back(v[i]); hashTable[aux] = vaux; }
    else hashTable[aux].push_back(v[i]);
  }
  return hashTable;
}

/* 
  Time:  O(M * n log n)
  Space: O(M*n)
*/
void groupAnagrams(vector<string> &v) { 
  unordered_map<string, vector<string> > hashTable = fillHashTable(v);

  v.clear();
  for(unordered_map<string, vector<string> >  ::iterator it = hashTable.begin(); it != hashTable.end(); it++)
    for(vector<string> :: iterator i = it->second.begin(); i != it->second.end(); i++)
      cout << *i << endl;
}

int main() {
  std::vector<string> v;

  string s = "abc";
  v.push_back(s);
  s = "bbb";
  v.push_back(s);
  s = "abcd";
  v.push_back(s);
  s = "bbb";
  v.push_back(s);
  s = "cab";
  v.push_back(s);
  s = "bbb";
  v.push_back(s);
  s = "adbc";
  v.push_back(s);
  s = "xyz";
  v.push_back(s);
  s = "x";
  v.push_back(s);
  s = "dcba";
  v.push_back(s);

  groupAnagrams(v);

  for (int i = 0; i < v.size(); ++i)
    cout << v[i] << endl;

  return 0;
}