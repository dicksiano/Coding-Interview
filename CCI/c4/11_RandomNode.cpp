#include <bits/stdc++.h>
using namespace std;

class  node {
public:
  node(int x) {
    this->elem = x;
    this->size = 1;
    this->l = NULL;
    this->r = NULL;
  }
  ~node();

  node *l;
  node *r;

  node getRandomNode() {
    int p = 1 + rand()%this->size;
    if(p < this->l->size) return l->getRandomNode();
    else if(p == this->l->size) return *this;
    else return r->getRandomNode();
  }

  node insert(int x) {
    this->size++;
    if(x <= this->elem) {
      if(this->l == NULL) this->l = new node(x);
      else this->l->insert(x);
    }
    else {
      if(this->r == NULL) this->r = new node(x);
      else this->r->insert(x);
    }
  }

private:
  int elem;
  int size;
};

int main() {
  return 0;
}