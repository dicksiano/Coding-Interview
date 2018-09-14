#include <iostream>
#include <cmath>
#include <string>
using namespace std;

/*
	Time: O(n)
	Space: O(1)
*/
bool checkEdit(string small, string big) {
	bool hasDif = false;
	int j = 0;

	for (int i = 0; i < small.size(); i++, j++) {
		if(small[i] != big[j]) {
			if(hasDif) return false; // Two differences
			hasDif = true; // First difference
			if(small.size() != big.size()) {
				j++;
				if(small[i] != big[j]) return false;
			}
		}
	}
	return true;
}

bool isEdit(string x, string y) {
	if(abs(x.size() - y.size()) > 1 ) return false; // Really important: difference size can only be 0 or 1
	
	if(x.size() >= y.size() ) return checkEdit(y,x);
	return checkEdit(x,y);
}

int main() {
	string x,y;
	while(1) {
		cin >> x >> y;
		cout << isEdit(x,y) << endl << endl;
	}
	return 0;
}