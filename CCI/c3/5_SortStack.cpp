#include <iostream>
#include <stack>
using namespace std;

/*
	Time: O(n²)
	Space: O(n) - aux queue

	Pop all elements that are bigger than the current one.
	In the end, put all elements from the aux stack in the principal stack.
*/
void sortStack( stack<int> &s ) {
	stack<int> aux;
	int curr;

	while(!s.empty()) {
		curr = s.top(); s.pop();

		while(!aux.empty() && curr < aux.top() ) {
			s.push(aux.top());
			aux.pop();
		}
		aux.push(curr);
	}

	while(!aux.empty()) {
		s.push(aux.top());
		aux.pop();
	}
}
void printStack(stack<int> s) {
	while( !s.empty() ) {
		cout << s.top() << endl;
		s.pop();
	}
	cout << "empty" << endl << endl;
}

int main() {
	stack<int> s;
	
	s.push(334);
	s.push(3234);
	s.push(4233);
	s.push(0);
	s.push(33674);
	s.push(-8973);
	s.push(243);
	s.push(3234);
	s.push(343);
	s.push(3);
	s.push(8973);

	sortStack(s);

	printStack(s);

	return 0;
}