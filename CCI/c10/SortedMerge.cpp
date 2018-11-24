#include <bits/stdc++.h>
using namespace std;

/* 
  Time:  O(n)
  Space: O(1)
*/
void sortedMerge(vector<int> &a, vector<int> b, int i) {
  int k = a.size() - 1;
  int j = b.size() - 1;
  i--;
  while(i >= 0 && j >= 0) {
    if(a[i] > b[j]) a[k--] = a[i--];
    else a[k--] = b[j--];
  } 
  while(i >= 0) a[k--] = a[i--];
  while(j >= 0) a[k--] = b[j--];
}

int main() {
  int myints[] = {-40,-20,-1,1,2,3,5,7,9,12,13,-1,-1,-1,-1,-1};
  vector<int> a (myints, myints + sizeof(myints) / sizeof(int) );

  //int myints2[] = {-500, -400,-400,-100,-94};
    //int myints2[] = {-50, 1,4,10,14};
  int myints2[] = {500, 1400,2400,3100,5594};
  vector<int> b (myints2, myints2 + sizeof(myints2) / sizeof(int) );

  for (int i = 0; i < a.size(); ++i)
    cout << a[i] << " ";
  cout << endl;
  for (int i = 0; i < b.size(); ++i)
    cout << b[i] << " ";
  cout << endl;
  sortedMerge(a,b,11);
  for (int i = 0; i < a.size(); ++i)
    cout << a[i] << " ";
  cout << endl;
  
  return 0;
}