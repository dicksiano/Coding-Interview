#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 1001

/*
  Classic Coin DP!

  Time: O(n * m)
  Space: O(n * m)
*/
int backtrack(int x, int state, vector<int> coins, int dpTable[][4]) {
  if(x < 0 || state >= coins.size()) return 0;    // Invalid choice
  if(x == 0) return 1;                            // Finished the staircase

  if(dpTable[x][state] == -1) {
    dpTable[x][state]   = backtrack(x,state+1,coins,dpTable) + backtrack(x-coins[state],state,coins,dpTable);
  }
  
  return dpTable[x][state];
}

int numOfWays(int x) {
  int dpTable[MAX_SIZE][4];
  vector<int> coins; 
  
  coins.push_back(1); coins.push_back(5); coins.push_back(10); coins.push_back(25); // Possible coins

  memset(dpTable, -1, sizeof dpTable);
  return backtrack(x, 0, coins, dpTable);
}

int main() {
  cout << numOfWays(1) << endl;
  cout << numOfWays(13) << endl;
  cout << numOfWays(10) << endl;
  cout << numOfWays(25) << endl;
  cout << numOfWays(100) << endl;
  return 0;
}