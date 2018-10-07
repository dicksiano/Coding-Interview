#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

/* 
  Time: O(n)
  Space: O(n) - recursion stack
              - Tree could be not balanced. Worst case: n
*/
bool bst(node *head, node* mini, node* maxi) {
  if(head == NULL) return true;

  if(mini != NULL) 
    if(head->elem < mini->elem) return false;
  
  if(maxi != NULL) 
    if(head->elem > maxi->elem) return false;
  
  return bst(head->left, mini, head) && bst(head->right, head, maxi);
}
bool validateBST(node *head) {
  return bst(head, NULL, NULL);
}


int main() {
  node * head = new node(4);
  head->left = new node(2);
  head->right = new node(6);
  
  node *l = head->left;
  l->left = new node(1);
  l->right = new node(3);

  node *r = head->right;
  r->left = new node(5);
  r->right = new node(7);

  cout << validateBST(head) << endl; // 1

  head = new node(20);
  head->left = new node(10);
  head->right = new node(30);
  
  l = head->left;
  l->right = new node(25);


  cout << validateBST(head) << endl; // 0

  head = new node(20);
  head->left = new node(10);
  head->right = new node(30);
  
  r = head->right;
  r->left = new node(19);

  cout << validateBST(head) << endl; // 0
  return 0;
}