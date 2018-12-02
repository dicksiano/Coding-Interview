#include <bits/stdc++.h>
using namespace std;

int mini(int a, int b, int c) { return min(a,min(b,c)); }

int maxi(int a, int b, int c) { return max(a,max(b,c)); }

int mid(int a, int b, int c) { 
  if( (a > b && a < c) || (a > c && a < b)) return a;
  if( (b > a && b < c) || (b > c && b < a)) return b;
  return c;
}

void pv(std::vector<int> &v, int i) {
  int x = mini(v[i], v[i+1],v[i+2]);
  int y = mid(v[i], v[i+1],v[i+2]); 
  int z = maxi(v[i], v[i+1],v[i+2]); 

  v[i] = z;
  v[i+1] = x;
  v[i+2] = y;
}

/* 
  Time:  O(n)
  Space: O(1)
*/
void peaksAndValleys(vector<int> &v) {
  for (int i = 0; i < v.size()-2; i = i + 2)
    pv(v,i);
}

int main() {
  int myints[] = {5, 3, 1, 2, 3};
  vector<int> v (myints, myints + sizeof(myints) / sizeof(int) );

  for (int i = 0; i < v.size(); ++i)
    cout << v[i] << " ";
  cout << endl;
  peaksAndValleys(v);
  for (int i = 0; i < v.size(); ++i)
    cout << v[i] << " ";
  return 0;
}