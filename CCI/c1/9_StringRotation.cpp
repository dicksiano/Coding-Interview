#include <iostream>
#include <string>
using namespace std;

bool isSubstring( string str, string sub ) {
	string::size_type n;
	n = str.find(sub); // Check if is substring

	if(n == string::npos )
		return false;
	return true;
}

/*
	Time: O(n)
	Space: O(n)
*/
bool isRotation( string s1, string s2) {
	if( s1.size() != s2.size() )
		return false;
	if( s1.size() > 0 ) {
		string aux = s1 + s1;
		return isSubstring(aux,s2);
	}
	return false;
}

int main() {
	string s1, s2;

	while(1) {
		cin >> s1 >> s2;

		cout << isRotation(s1,s2) << endl << endl;
	}
	return 0;
}
