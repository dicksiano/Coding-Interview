#include <bits/stdc++.h>
using namespace std;

/*
	Time:  O(d)
	Space: O(1)
*/
int nextB(int x) {
	for (int i = 0; ; ++i) {
		if( (x & (1<<i)) && !(x & (1<<(i+1)) ) )
			return x - (1<<i) + (1<<(i+1));
	}
}

int nextS(int x) {
	for (int i = 0; ; ++i) {
		if( !(x & (1<<i)) && (x & (1<<(i+1)) ) )
			return x + (1<<i) - (1<<(i+1));
	}
}

int main() {
	cout << "100100101001" << endl;
	cout << bitset<12>(nextS(0b100100101001)) << endl;
	cout << bitset<12>(nextB(0b100100101001)) << endl;

	return 0;
}