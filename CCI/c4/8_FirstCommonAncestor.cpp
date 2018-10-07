#include <bits/stdc++.h>
using namespace std;

/* 
  Solution with pointer to parents

  Time: O(log n)
  Space: O(1)

  i.   Find the difference from the root.
  ii.  Take the deepest element and make it go to the same level of the other node
  iii. Make them bouth go to their parents until they find each other
*/
class node {
  public:
    node(int x, node* parent) {
      this->elem = x;
      this->left = NULL;
      this->right = NULL;
      this->parent = parent;
    }
    ~node();    

    int elem;
    node *left, *right, *parent;
};

int depth(node *root) {
  int ans = 0;
  while( root != NULL ){
    root = root->parent;
    ans++;
  }
  return ans;
}

int firstCommonAncestor1(node *p, node *q) {
  if(p == NULL || q == NULL) return -1; // error
  if(p == q) return p->elem;

  int pDepth = depth(p);
  int qDepth = depth(q);

  for (int i = 0; i < pDepth-qDepth; ++i)
    p = p->parent;
  for (int i = 0; i < qDepth-pDepth; ++i)
    q = q->parent;
  
  while(p != q) { p = p->parent; q = q->parent; }

  return p->elem;
}

/* 
  Solution with no extra pointers

  Time: O(n)
  Space: O(log n) - recursion stack
*/

bool isSubtree(node *root, node *p) {
  if(root == NULL || p == NULL) return false;
  if(root == p) return true;

  return isSubtree(root->left,p) || isSubtree(root->right,p);
}
int firstCommonAncestor2(node *root, node *p, node *q) {
  if(p == NULL || q == NULL || root == NULL) return -1; // error
  if(p == q) return p->elem;

  bool isPLeft = isSubtree(root->left,p);
  bool isQLeft = isSubtree(root->left,q);

  if(isPLeft != isQLeft) return root->elem;

  if(isPLeft) return firstCommonAncestor2(root->left,p,q);
  else return firstCommonAncestor2(root->right,p,q);
}

int main() {
  node * head = new node(8, NULL);
  head->left = new node(4, head);
  head->right = new node(12, head);
  
  node *l = head->left;
  l->left = new node(2, l);
  l->right = new node(6, l);

  node *ll = l->left;
  ll->left = new node(1, ll);
  ll->right = new node(3,ll);

  node *lr = l->right;
  lr->left = new node(5,lr);
  lr->right = new node(7,lr);

  node *r = head->right;
  r->left = new node(10,r);
  r->right = new node(14,r);

  node *rl = r->left;
  rl->left = new node(9,rl);
  rl->right = new node(11,rl);

  node *rr = r->right;
  rr->left = new node(13,rr);
  rr->right = new node(15,rr);

  cout << "LCA (" << ll->left->elem << "," << l->elem << "): " << firstCommonAncestor1(ll->left,l) << endl;
  cout << "LCA (" << ll->left->elem << "," << l->elem << "): " << firstCommonAncestor2(head,ll->left,l) << endl;
  return 0;
}