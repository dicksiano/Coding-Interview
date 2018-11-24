#include <bits/stdc++.h>
using namespace std;

bool checkLine(int M[][8], int i, int j) {
  for (int k = j-1; k >= 0; k--)
    if(M[i][k]) return false;
  return true;
}

bool checkUp(int M[][8], int i, int j) {
  i--; j--;
  while(i >= 0 && j >= 0){
    if(M[i][j]) return false;
    i--; j--;
  }
  return true;
}

bool checkDown(int M[][8], int i, int j) {
  i++; j--;
  while(i < 8 && j >= 0) {
    if(M[i][j]) return false;
    i++; j--;
  }
  return true;
}

bool isValid(int M[][8], int i, int j) { return checkLine(M,i,j) && checkUp(M,i,j) && checkDown(M,i,j); }

void printM(int M[][8]) {
  for (int i = 0; i < 8; ++i)  {
    for (int j = 0; j < 8; ++j)
      cout << M[i][j] << " ";
    cout << endl;
  }

  cout << endl << "*" << endl << endl;
}

void backtrack(int M[][8], int c) {
  if(c == 8) {printM(M); return;}

  for (int i = 0; i < 8; ++i) {
    if(isValid(M,i,c)) {
      M[i][c] = 1;
      backtrack(M,c+1);
      M[i][c] = 0;
    }
  }
}

void print8x8() {
  int M[8][8]; memset(M,0,sizeof M);
  backtrack(M,0);
}

int main() {
  print8x8();
  return 0;
}