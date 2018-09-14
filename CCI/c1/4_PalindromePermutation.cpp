#include <iostream>
#include <string>
using namespace std;

/* 
	Time: O(n)
	Space: O(1)
*/
bool isPalPerm(string str) {
	int letters[30] = {0};

	for (int i = 0; i < str.size(); ++i) {
		if(str[i] >= 'a' && str[i] <= 'z')	letters[ str[i] - 'a' ]++;	// lowercase
		else if(str[i] >= 'A' && str[i] <= 'Z')	letters[ str[i] - 'A' ]++; // uppercase
	}
	
	int numOdd = 0;
	for (int i = 0; i < 30; ++i)
		if(letters[i]%2 != 0)
			numOdd++;

	return (numOdd < 2); // The number of chars with odd counter must be 0 or 1
}

int main() {
	string str;

	while(1) {
		getline(cin,str);
		cout << isPalPerm(str) << endl << endl;
	}
	return 0;
}