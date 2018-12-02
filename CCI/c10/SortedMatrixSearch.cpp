#include <bits/stdc++.h>
using namespace std;

/* 
  Time:  O(n)
  Space: O(1)
*/
bool sortedMatrixSearch(vector< vector<int> > &M, int x) {
  int i = 0;
  int j = M[0].size() -1;

  while(i < M.size() && j >= 0) {
      if(M[i][j] == x) return true;
      else if( M[i][j] < x) i++
      else j--;
  }
  return false;
}

int main() {
  return 0;
}