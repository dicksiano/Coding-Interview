#include <bits/stdc++.h>
using namespace std;

int flipBitToWin(int x) {
	int current = 0, prev = 0, maxi = -1;

	for (int i = 0; (1 << i) <= x; ++i) {
		if(x & (1 << i)) current++;
		else {
			prev = current;
			current = 0;
		}
		maxi = max(current + prev, maxi);		
	}
	return maxi + 1;
}

int main() {
	
	cout << flipBitToWin(1775) << endl << endl;
	cout << flipBitToWin(0b1101111001111) << endl << endl;
	cout << flipBitToWin(0b11001111001111) << endl << endl;
	cout << flipBitToWin(0b111110011111) << endl << endl;
	return 0;
}