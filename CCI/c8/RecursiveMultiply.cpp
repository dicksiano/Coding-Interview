#include <bits/stdc++.h>
using namespace std;

int rm(int mini, int maxi) {
  if(!mini) return 0;
  
  int halfProd = rm(mini >> 1,maxi);
  
  return (mini%2 == 1) ? (halfProd + halfProd + maxi) : (halfProd + halfProd);
}

int recursiveMultiply(int x, int y) {
  return rm(min(x,y),max(x,y));
}

int main() {
  cout << recursiveMultiply(0,1) << endl;
  cout << recursiveMultiply(8,1) << endl;
  cout << recursiveMultiply(1,8) << endl;
  cout << recursiveMultiply(10,23) << endl;
  
  return 0;
}