#include <bits/stdc++.h>
using namespace std;

/*
  Binary Search - Divide and Conquer

  Time:  O(log n)
  Space: O(log n) - Size of the stack
*/
int fmi(vector<int> A, int a, int b) {
  if(a == b) {
    if(a == A[a]) return a;
    else return -1;
  }

  int mid = (a+b)/2;
  if(A[mid] > mid) return fmi(A,a,mid-1);
  if(A[mid] == mid) return mid;

  return fmi(A,mid + 1, b);
}

int findMagicIndex(vector<int> A) {
  return fmi(A,0,A.size());
}

int main() {
  int myints[] = {-40,-20,-1,1,2,3,5,7,9,12,13};
  vector<int> v (myints, myints + sizeof(myints) / sizeof(int) );

  cout << findMagicIndex(v) << endl;

  int myints2[] = {-40,-20,-1,1,2,3,5,8,9,12,13};
  vector<int> v2 (myints2, myints2 + sizeof(myints2) / sizeof(int) );

  cout << findMagicIndex(v2) << endl;
  return 0;
}