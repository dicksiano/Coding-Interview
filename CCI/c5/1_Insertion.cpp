#include <bits/stdc++.h>
using namespace std;

/*
	Time: O(1)  - all operations are O(1) regardless i, j
	Space: O(1) - no extra space
*/
int insertion(int n, int m, int i, int j) {
	int b = m << i;
	int a = (2 << 31) -1;

	a = a << j;
	a = a | ((2 << i) -1);

	return ( (n & a) | b);
}

int main() {
	int N = 0b10000000000;
	int M = 0b10011;

	cout << insertion(N,M,2,6) << " -> " << bitset<16>(insertion(N,M,2,6)) << endl << endl;

	M = 0b11;
	cout << insertion(N,M,2,4) << " -> " << bitset<16>(insertion(N,M,2,6)) << endl << endl; 
	
	M = 0b1111;
	cout << insertion(N,M,2,6) << " -> " << bitset<16>(insertion(N,M,2,6)) << endl << endl; 
	
	return 0;
}