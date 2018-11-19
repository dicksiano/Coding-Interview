#include <bits/stdc++.h>
using namespace std;

/*
  Time:  O(2^n)
  Space: O(2^n)
*/
void backtrack(int l, int r, string &s) {
  if(r < l) return;
  if(l == 0 && r == 0) cout << s << endl;

  s = s + '(';
  if(l > 0) backtrack(l-1, r, s);
  s[s.size() -1 ] = ')';
  if(r > 0) backtrack(l, r-1, s);
  s.erase( s.size() -1 );
}

void printParens(int x) {
  string s = "";
  backtrack(x, x, s);
}

int main() {
  cout << 3 << endl;
  printParens(3);

  cout << endl << 4 << endl;
  printParens(4);
  return 0;
}