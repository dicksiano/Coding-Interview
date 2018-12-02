#include <bits/stdc++.h>
using namespace std;

/*
    Time:  O(n)
    Space: O(n) - Recursion stak
*/
int bs(vector<int> v, int l, int r, int x) {
    if(l > r) return -1;
    int m = (l + r) / 2;
    if(v[m] == x) return m;

    if(v[l] < v[m]) {   // Left side is sorted
        if( v[l] <= x && x < v[m]) return bs(v, l, m - 1, x);
        else return bs(v, m + 1, r, x);
    } else if(v[m] < v[r]) {            // Right side is sorted
        if( v[m] < x && x <= v[r]) return bs(v, m + 1, r, x);
        else return bs(v, l, m-1, x);
    } else if(v[l] == v[m]) return bs(v, m + 1, r, x);
    else return bs(v, l, m - 1, x);
}

int main() {
    vector<int> v;

    for(int i = 8; i <= 12; i++) v.push_back(i);
    for(int i = 1; i<= 7; i++) v.push_back(i);

    for(int i = 1; i < 13; i++) cout << "v[" << bs(v, 0, v.size() - 1, i) << "] = " << i << endl;

    v.clear(); cout << endl;
    for(int i = 8; i <= 12; i++) v.push_back(10);
    for(int i = 1; i<= 7; i++) v.push_back(i);

    for(int i = 1; i < 11; i++) cout << "v[" << bs(v, 0, v.size() - 1, i) << "] = " << i << endl;
    return 0;
}