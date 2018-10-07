#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

class linkedListNode {
  public:
    linkedListNode(int x) {
      this->elem = x;
      this->next = NULL;
    }
    ~linkedListNode();    

    int elem;
    linkedListNode *next;
};

void createList(node *head, vector<linkedListNode *> &v, int depth) {
  if(head == NULL) return;

  if(v.size() < depth) v.push_back(new linkedListNode(head->elem));
  else {
    linkedListNode *p = v[depth-1];
    while(p->next != NULL)
      p = p->next;
    p->next = new linkedListNode(head->elem);
  }
  createList(head->left,v,depth+1);
  createList(head->right,v,depth+1);
}

vector<linkedListNode *> listOfDepths(node *head) {
  vector<linkedListNode *> ans;
  createList(head,ans,1);
  return ans;
}

int main() {
  node * head = new node(1);
  head->left = new node(2);
  head->right = new node(3);
  
  node *l = head->left;
  l->left = new node(4);
  l->right = new node(5);

  node *r = head->right;
  r->left = new node(6);
  r->right = new node(7);

  vector<linkedListNode *> ans = listOfDepths(head);
  for (int i = 0; i < ans.size(); ++i) {
    cout << "\nDepth " << i << ": " ;
    linkedListNode *p = ans[i];
    while(p != NULL) {
      cout << p->elem << "->";
      p = p->next;
    }
    cout << "NULL";
  }
  cout << endl;
  return 0;
}