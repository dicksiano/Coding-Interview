#include <bits/stdc++.h>
using namespace std;
#define NULL_NODE -99999

class node {
  public:
    node(int x) {
      this->elem = x;
      this->left = NULL;
      this->right = NULL;
    }
    ~node();    

    int elem;
    node *left, *right;
};

int getMaxElem(node * root) {
  if(!root) return 0;
  return max( abs(root->elem), max(getMaxElem(root->left),getMaxElem(root->left)) );
}

int numOfDigits(int x) {
  int res = 0;
  for(; x > 0; x /= 10, res++);
  return res;
}

void createList(node *head, vector<vector<int> > &v, int depth) {
  if(v.size() < depth) {
    std::vector<int> aux;
    v.push_back(aux);
  }
  if(head == NULL) {v[depth-1].push_back(NULL_NODE); return;}

  v[depth-1].push_back(head->elem);
  createList(head->left,v,depth+1);
  createList(head->right,v,depth+1);
}

vector<vector<int> > listDepths(node *head) {
  vector<vector<int> > ans;
  createList(head,ans,1);
  return ans;
}

void printByLevels(node *head) {
  vector<vector<int> > ans = listDepths(head);
  ans.pop_back();
  int elemSize = 1 + numOfDigits(getMaxElem(head));
  int numSpaces, length = 1 << (ans.size() - 1);
  length = length * elemSize + 7 * (length + 1);
  for (int i = 0; i < ans.size(); ++i) {
    cout << "\nDepth " << i << ":";
    numSpaces = (length - (1 << i) * elemSize ) / ( 1 + (1 << i) );
    for (int j = 0; j < ans[i].size(); ++j) {
      for(int k = 0; k < numSpaces; k++) cout << " ";
      if(ans[i][j] != NULL_NODE)
        cout << ((ans[i][j] > 0) ? "+":"") << ans[i][j];
      else  
        cout << " ";
    }
  }
  cout << endl;
}