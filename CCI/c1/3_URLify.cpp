#include <string>
#include <iostream>
using namespace std;

/*
	Time: O(n)
	Space: O(1) -- In place
*/
void urlify(string &str, int tl) {
	int j = str.size() - 1;

	for(int i = tl - 1 ; i >= 0; i--) {
		if( str[i] == ' ') {
			str[j--] = '0';
			str[j--] = '2';
			str[j--] = '%';
		}
		else str[j--] = str[i];
	}
}

int main() {
	string str;
	int tl;
	while(1) {
		getline(cin, str);
		cin >> tl;
		cout << str << "***" << endl;
		urlify(str,tl);
		cout << str << "***" << endl << endl;
		cin.ignore();
	}
	return 0;
}