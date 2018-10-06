#include <bits/stdc++.h>
#include "tree.h"

node *mt(std::vector<int> v, int s, int e) {
  if(e < s || s < 0 || e >= v.size()) return NULL;
  if(e == s) return new node(v[s]);

  int mid = (s+e)/2;
  node *root = new node(v[mid]);

  root->left = mt(v,s,mid-1);
  root->right = mt(v,mid+1,e);

  return root;  
}
node *minimalTree(std::vector<int> v) {
  return mt(v,0,v.size()-1);
}

int main() {
  vector<int> v;
  for (int i = 1; i < 32; ++i) v.push_back(i);

  node *head = minimalTree(v);
  printByLevels(head);
  return 0;
}