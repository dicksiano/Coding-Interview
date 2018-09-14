#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

/* Brute Force
	Time: O(n²) -- compare every char to every other char
	Space: O(1)
*/


/*
	Time: O(n)
	Space: O(1) -- with extra space
*/
bool isUnique(string str) {
	unordered_map<char,int> charac; // Hash table -- extra space

	for(int i = 0; i < str.size(); i++) {
		if( charac.find( str[i] ) == charac.end() )
			charac[ str[i] ] = 1;
		else return false;
	}
	return true;
}

/*
	Time: O(n logn)
	Space: O(1) -- no extra space
*/
bool isUnique2(string str) {
	if(str.size() > 256 ) return false; // Optimization! Pigeonhole principle.

	sort(str.begin(), str.end() ); // Sort string: O(n logn)
	for(int i = 0; i  < str.size() - 1; i++)
		if(str[i] == str[i+1])
			return false;
	return true;
}

int main() {
	string str;
	while(1) {
		cin >> str;
		cout << isUnique(str) << endl;
	}
	return 0;
}