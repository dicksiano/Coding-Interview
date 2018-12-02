#include <bits/stdc++.h>
using namespace std;

int bs(vector<int> v, int l, int r, int x) {
    if(l == r) {
        if(v[l] == x) return l;
        return -1;
    }

    int m = (l + r) / 2;
    if( v[m] == x ) return m;

    if(x < v[m]) return bs(v, l, m-1, x);
    return bs(v, m + 1, r, x);
}

int rotedBS(vector<int> v, int l, int r, int x) {
    int m = (l + r) / 2;

    if(v[l] <= v[m]) {   // Left side is sorted
        if( v[l] <= x && x <= v[m]) return bs(v, l, m, x);
        else return rotedBS(v, m + 1, r, x);
    } else {            // Right side is sorted
        if( v[m] <= x && x <= v[r]) return bs(v, m, r, x);
        else return rotedBS(v, l, m-1, x);
    }
}

int main() {
    vector<int> v;

    for(int i = 8; i <= 12; i++) v.push_back(i);
    for(int i = 1; i<= 7; i++) v.push_back(i);

    for(int i = 1; i < 13; i++) cout << "v[" << rotedBS(v, 0, v.size() - 1, i) << "] = " << i << endl;
    return 0;
}