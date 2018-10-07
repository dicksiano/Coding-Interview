#include <bits/stdc++.h>
using namespace std;

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

/*
  Time: O(log n)
  Space: O(1)

  i. Node has right son
      - Go to right son
      - Go to left as much as possible
  ii. Node hasn't right son
      - Go to parent as long as the parent is smaller than node

*/
int sucessor(node *root) { 
  if(root == NULL) return -1; // error

  if(root->right == NULL) {
    node *p = root;
    while(p->elem <= root->elem) {
      p = p->parent;
      if(p == NULL) return -1; // Last
    }
    return p->elem;
  }

  node *p = root->right;
  while(p->left != NULL) p = p->left;

  return p->elem;
}

int main() {
  node * head = new node(8, NULL);
  head->left = new node(4, head);
  head->right = new node(12, head);
  
  node *l = head->left;
  l->left = new node(2, l);
  //l->right = new node(6, l);

  node *ll = l->left;
  ll->left = new node(1, ll);
  ll->right = new node(3,ll);

  //node *lr = l->right;
  //lr->left = new node(5,lr);
  //lr->right = new node(7,lr);

  node *r = head->right;
  r->left = new node(10,r);
  r->right = new node(14,r);

  node *rl = r->left;
  rl->left = new node(9,rl);
  rl->right = new node(11,rl);

  node *rr = r->right;
  rr->left = new node(13,rr);
  rr->right = new node(15,rr);


  cout << head->elem << ": " << sucessor(head) << endl;
  cout << l->elem << ": " << sucessor(l) << endl;
  cout << r->elem << ": " << sucessor(r) << endl;
  cout << ll->elem << ": " << sucessor(ll) << endl;
  //cout << sucessor(lr) << endl;

  cout << rl->elem << ": " << sucessor(rl) << endl;
  cout << rr->elem << ": " << sucessor(rr) << endl;
  cout << ll->left->elem << ": " << sucessor(ll->left) << endl;
  cout << ll->right->elem << ": " << sucessor(ll->right) << endl;
  //cout << sucessor(lr->left) << endl;

  //cout << sucessor(lr->right) << endl;
  cout << rl->left->elem << ": " << sucessor(rl->left) << endl;
  cout << rl->right->elem << ": " << sucessor(rl->right) << endl;
  cout << rr->left->elem << ": " << sucessor(rr->left) << endl;
  cout << rr->right->elem << ": " << sucessor(rr->right) << endl;
  return 0;
}