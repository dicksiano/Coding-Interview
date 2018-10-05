#include <bits/stdc++.h>
using namespace std;

/*
	Time: O(d) - d is the number of 1's, not the total number of digits
	Space: O(1)

	a ^ b : only digits that are different from a and b
	The biggest hack is: 	c = c & (c-1)
*/
int conversion(int a, int b) {
	int count = 0;
	for (int c = a ^ b; c != 0; c = c & (c-1)) {
		count++;
	}
	return count;
}
int main() {
	cout << conversion(29,15) << endl;

	return 0;
}
