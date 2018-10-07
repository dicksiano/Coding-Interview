#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

/* 
  Time:  O(n)
  Space: O(n) - recursion stack in a not balanced tree
              - hash map
*/
int paths(node *root, int x, map<int,int> &hashMap, int currentSum) {
  if(root == NULL) return 0;

  int ans = 0;

  currentSum = currentSum + root->elem;
  if(currentSum == x) 
    ans++;

  int delta = currentSum - x; // Delta is the difference from currentSum and target: how much we've passed

  if(hashMap.find(delta) != hashMap.end()) // Check if there is an old path that sums delta
    ans += hashMap[delta];

  if(hashMap.find(currentSum) != hashMap.end()) 
    hashMap[currentSum] = 1;
  else 
    hashMap[currentSum] = hashMap[currentSum] + 1;

  ans += paths(root->left,x,hashMap,currentSum) + paths(root->right,x,hashMap,currentSum);

  hashMap[currentSum] = hashMap[currentSum] - 1;

  return ans;
}

int pathWithSum(node *root, int x) {
  map<int,int> hashMap;
  return paths(root,x,hashMap,0);
}

int main() {
  
  node *head = new node(10);
  head->left = new node(5);
  head->right = new node(-3);
  
  node *l = head->left;
  l->left = new node(3);
  l->right = new node(1);
  
  node *ll = l->left;
  ll->left = new node(3);
  ll->right = new node(-2);
  
  node *lr = l->right;
  lr->right = new node(2);

  node *r = head->right;
  r->right = new node(11);

  printByLevels(head);

  cout << pathWithSum(head,8) << endl;

  return 0;
}