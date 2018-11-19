#include <iostream>
#include <stack>
using namespace std;

/*
	Time:  O(2^n)
	Space: O(2^n)
*/	
void hanoi(int n, stack<int> &begin, stack<int> &aux, stack<int> &end ) {
	if( n == 1 ) {
		end.push(begin.top());
		begin.pop();
		return;
	}
	hanoi(n-1, begin, end, aux);

	end.push(begin.top());
	begin.pop();

	hanoi(n-1, aux, begin, end);
}

void printStack(stack<int> s) {
	while( !s.empty() ) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << "empty" << endl << endl;
}

int main() {
	stack<int> b,a,e;

	for(int i = 0; i < 8; i++)
		b.push(i);


	printStack(b); printStack(a); printStack(e);

	hanoi(8,b,a,e);

	printStack(b); printStack(a); printStack(e);

	return 0;
}