#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

/* Brute Force
	Time: O(n²)
	Space: O(1) -- no extra space
*/

/*
	Time: O(n logn)
	Space: O(1) -- depends on sort implementation

*/
bool isAnagram( string first, string sec ) {
	sort(first.begin(), first.end() );
	sort(sec.begin(), sec.end() );

	return !first.compare(sec);
}

/* 
	Time: O(n)
	Space: O(1) -- there are just 256 possible chars
*/
bool isAnagram2(string first, string sec) {
	if(first.size() != sec.size() ) return false; // Little optimization

	int f[256] = {0}, s[256] = {0};
	for( int i = 0; i < first.size(); i++){
		f[ first[i] ]++;
		s[ sec[i] ]++;
	}
	for(int i = 0; i < 256; i++) // Compare counters
		if(f[i] != s[i]) return false;
	
	return true;
}

int main() {
	string first, sec;

	while(1) {
		cin >> first >> sec;

		cout << isAnagram(first,sec);
		cout << isAnagram2(first,sec);
	}
	return 0;
}