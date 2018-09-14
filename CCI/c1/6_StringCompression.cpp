#include <iostream>
#include <string>
using namespace std;

/*
	Time: O(n)
	Space: O(n) -- extra space for compressed string
*/
string stringCompression(string str) {
	char curr = str[0];
	string ans;
	int counter = 1;

	for (int i = 1; i < str.size(); ++i) {
		if(curr == str[i] )
			counter++;
		else {
			ans = ans + curr + to_string(counter); // C++ 11

			curr = str[i];
			counter = 1;
		}
	}
	ans = ans + curr + to_string(counter); // WARNING! Add the last letter
	return (str.size() > ans.size()) ? ans : str;
}

int main() {
	string str;

	while(1) {
		cin >> str;
		cout << stringCompression(str) << endl << endl;
	}
	return 0;
}