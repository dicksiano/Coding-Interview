#include <iostream>
#include <stack>
using namespace std;

/*
	Pop all elements that are bigger than the new one.
	Put all elements bigger in the aux stack.
	In the end, put all elements in the aux stack in the stack.
*/
void sortStack( stack<int> &s ) {
	stack<int> aux;
	int curr;

	while(!s.empty()) {
		curr = s.top(); s.pop();

		if(aux.empty()) 
			aux.push(curr);
		else {
			while(curr < aux.top() ) {
				s.push(aux.top());
				aux.pop();

				if(aux.empty()) // Avoid crash of using top() in a empty queue
					break;
			}
			aux.push(curr);
		}
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