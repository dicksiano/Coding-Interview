#include <bits/stdc++.h>
using namespace std;

#define MAXI_ 10001

class box {
public:
  box(int w, int h, int d) {
    this->w = w;
    this->h = h;
    this->d = d;
  }
  int w,h,d;
};

bool comp(box x, box y) { return x.h > y.h; }

bool isValid(box x, int w, int d) { return (x.w < w) && (x.d < d); }

int backtrack(int i, vector<box> v, int w, int d) {
  if( i == v.size() ) return 0;

  int x = 0;
  if(isValid(v[i], w,d)) {
    x = v[i].h + backtrack(i+1, v, v[i].w, v[i].d);
  }

  return max(x, backtrack(i+1, v, w, d));
}

int stackOfBoxes(vector<box> v) {
  sort(v.begin(), v.end(), comp);
  return backtrack(0, v, MAXI_, MAXI_);
}

int main() {
  vector<box> v;
  v.push_back(*(new box(1,2,3)));
  v.push_back(*(new box(3,7,4)));
  v.push_back(*(new box(4,10,6)));

  cout << stackOfBoxes(v) << endl;
  return 0;
}