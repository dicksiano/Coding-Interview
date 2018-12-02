#include <bits/stdc++.h>
using namespace std;

/*
  Time:  O(n) - worst case (all empty strings)
  Space: O(log n) - Avoid rcursion call with empty strings
*/
int bs(std::vector<string> v, string str, int s, int e) {
  if(s == e) {
    if(v[s] == str) return s;
    return -1; 
  }
  int mid = (s+e)/2;

  if(v[mid] == "") {
    for (int i = mid+1; i <= e ; ++i){  
      if(v[i] != "") {
        if(v[i] > str) 
          break;
        return bs(v,str,i,e);
      }
    }
    for (int i = mid-1; i >= s; i--){
      if(v[i] != "") {
        if(v[i] < str) 
          break;
        return bs(v,str,s,i);
      }
    }
    return -1;
  }

  if(v[mid] < str) return bs(v,str,mid+1,e);
  else if(v[mid] == str) return mid;
  return bs(v,str,s,mid-1);
}

int search(std::vector<string> v, string s) {
  return bs(v,s,0,v.size()-1);
}

int main() {
  std::vector<string> v;
  string s;

  s = "at";
  v.push_back(s);
  s = "";
  v.push_back(s);
  v.push_back(s);
  v.push_back(s);
  s = "ball";
  v.push_back(s);
  s = "";
  v.push_back(s);
  v.push_back(s);
  s = "car";
  v.push_back(s);
  s = "";
  v.push_back(s);
  s = "dad";
  v.push_back(s);
  s = "";
  v.push_back(s);

  for (int i = 0; i < v.size(); ++i)
   cout << "\"" << v[i] << "\" ";

  cout << endl;

  cout << search(v, "at") << endl;
  cout << search(v, "ball") << endl;
  cout << search(v, "car") << endl;
  cout << search(v, "dad") << endl;
  return 0;
}