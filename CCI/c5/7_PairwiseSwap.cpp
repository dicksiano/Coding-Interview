#include <bits/stdc++.h>
using namespace std;

/* 
	Time: O(1)
	Space: O(1)
*/
int pairwiseSwap(int x) {
	int a = x & 0b0101010101010101010101010101010;
	int b = x & 0b1010101010101010101010101010101;
	return (b << 1) | (a >> 1);
}

int main() {
	
	cout << "1001010100010111" << endl << bitset<16>(pairwiseSwap(0b1001010100010111)) << endl << endl;
	cout << "0111" << endl << bitset<4>(pairwiseSwap(0b0111)) << endl << endl;
	cout << "101" << endl << bitset<3>(pairwiseSwap(0b101)) << endl << endl;
	return 0;
}