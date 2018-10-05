#include <bits/stdc++.h>
using namespace std;

int flipBitToWin(int x) {
	int current = 0;
	int maxi = -1;
	int newStart;
	int hasZero = 0;

	for (int i = 0; (1 << i) <= x; ++i) {
		if(x & (1 << i)) {
			current++;
			maxi = max(current,maxi);

			if(x & (1 << newStart) == 0)
				newStart = i-1;
		}
		else {
			if(!hasZero) {
				hasZero = 1;
				current++;
				maxi = max(current,maxi);
				newStart = i;
			}
			else {
				hasZero = 0;
				current = 0;
				i = newStart;
			}
		}
	}
	return maxi;
}

int main() {
	
	cout << flipBitToWin(1775) << endl << endl;
	cout << flipBitToWin(0b1101111001111) << endl << endl;
	cout << flipBitToWin(0b11001111001111) << endl << endl;
	cout << flipBitToWin(0b111110011111) << endl << endl;
	return 0;
}