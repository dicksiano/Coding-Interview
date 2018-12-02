#include <bits/stdc++.h>
using namespace std;

class Listy {
public:
  Listy(std::vector<int> v) {
    for (int i = 0; i < v.size(); ++i)
      this->v.push_back(v[i]);
    this->size = v.size();
  }

  ~Listy() {
    v.clear();  
  }

  int elementAt(int i) {
    if(i > this->size-1) return -1;
    return this->v[i];
  }

private:
  int size;
  vector<int> v;
};

int binSearch(Listy l, int x, int s, int e) {
  if(s == e) {
    if(l.elementAt(s) != x)
      return -1;
    return s;
  }

  int mid = (s+e)/2;
  if(l.elementAt(mid) == -1)
    return binSearch(l, x, s, mid-1);

  if(x == l.elementAt(mid)) 
    return mid;
  else if(x < l.elementAt(mid)) 
    return binSearch(l, x, s, mid-1);
  else
    return binSearch(l, x, mid+1, e);
}

int search(Listy l, int x) {
  int i = 1;
  while(l.elementAt(i) != -1 && l.elementAt(i) < x)
    i *= 2;
  return binSearch(l, x, i/2, i);
}

int main() {
  vector<int> v;
  for (int i = 0; i < 16; ++i)
    v.push_back(i);

  Listy l(v);

  cout << 1 << " " << search(l, 1) << endl; 
  cout << 5 << " " << search(l, 5) << endl; 
  cout << 10 << " " << search(l, 10) << endl; 
  cout << 15 << " " << search(l, 15) << endl; 
  cout << 20 << " " << search(l, 20) << endl; 

  return 0;
}