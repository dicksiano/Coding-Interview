#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

/*
  Time: O(n + km)
  Spae: O(log n) - recursion stack
*/
bool check(node *x, node *y) {
  if(x == NULL && y == NULL) return true;
  if(x == NULL || y == NULL) return false;
  if(x->elem != y->elem) return false;

  return check(x->left,y->left) && check(x->right,y->right);
}

/* This solution works only with trees that has no repeated values */
bool checkSubtreeWrong(node *x, node *y) {
  if(y == NULL) return true; // All trees has null nodes
  if(x == NULL) return false;

  if(x->elem == y->elem) return check(x,y);

  return checkSubtreeWrong(x->left,y) || checkSubtreeWrong(x->right,y);
}

/* This solution also works trees that has repeated values */
bool checkSubtree(node *x, node *y) {
  if(y == NULL) return true; // All trees has null nodes
  if(x == NULL) return false;

  if(x->elem == y->elem) 
    if(check(x,y)) return true;

  return checkSubtree(x->left,y) || checkSubtree(x->right,y);
}

int main() {
  node * head = new node(8);
  head->left = new node(4);
  head->right = new node(12);

  node *l = head->left;
  l->left = new node(4);
  
  l = head->left->left;
  l->left = new node(2);
  l->right = new node(6);

  node *ll = l->left;
  ll->left = new node(1);
  ll->right = new node(3);

  node *lr = l->right;
  lr->left = new node(5);
  lr->right = new node(7);

  node *r = head->right;
  r->left = new node(10);
  r->right = new node(14);

  node *rl = r->left;
  rl->left = new node(9);
  rl->right = new node(11);

  node *rr = r->right;
  rr->left = new node(13);
  rr->right = new node(15);

  // Second Tree
  node *l2 = new node(4);
  l2->left = new node(2);
  l2->right = new node(6);

  node *ll2 = l2->left;
  ll2->left = new node(1);
  ll2->right = new node(3);

  node *lr2 = l2->right;
  lr2->left = new node(5);
  lr2->right = new node(7);

  cout << checkSubtreeWrong(head,l2) << ": fails in tree with repeated values!" << endl;
  cout << checkSubtree(head,l2) << endl;

  return 0;
}