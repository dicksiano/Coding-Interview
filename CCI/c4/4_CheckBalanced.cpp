#include <bits/stdc++.h>
using namespace std;

/*
  Time: O(n)
  Space: O(log n) - recursion stack
*/
pair<bool, int> isBalanced(node *root) {
  if(root == NULL) return make_pair(true,0);

  pair<bool, int> l = isBalanced(root->left);
  pair<bool, int> r = isBalanced(root->right);

  bool ans = l.first && r.first && (bool)(abs(l.second-r.second) < 2);
  int depth = max(l.second,r.second);

  return make_pair(ans,depth+1);
}

bool checkBalanced(node *root) {
  pair<bool, int> ans = isBalanced(root);
  return ans.first;
}
int main() {
  node * head = new node(1);
  head->left = new node(2);
  head->right = new node(3);
  
  node *l = head->left;
  l->left = new node(4);
  l->right = new node(5);


  cout << checkBalanced(head) << endl;
  return 0;
}