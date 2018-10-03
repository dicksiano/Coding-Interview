#include <iostream>
using namespace std;

/*
	Not the best solution, since it doesn't allow flexible size for each stack.
*/
class stackABC {
public:
	stackABC() {
		this->topA = -3;
		this->topA = -2;
		this->topA = -1;
	}
	void push(int x, char c) {
		if( c == 'A') { array[topA] = x; topA += 3; }
		else if( c == 'B') { array[topB] = x; topB += 3; }
		else if( c == 'C') { array[topC] = x; topC += 3; }
	}
	int top(char c) {
		if( c == 'A') { 
			if(topA < 0) { cout << "Exception! Empty Stack!" << endl; return 0; }
			return array[topA];
		}
		else if( c == 'B') { 
			if(topB < 0) { cout << "Exception! Empty Stack!" << endl; return 0; }
			return array[topB];
		}
		else if( c == 'C') { 
			if(topC < 0) { cout << "Exception! Empty Stack!" << endl; return 0; }
			return array[topC];
		}
	}
	void pop(char c) {
		if( c == 'A') { 
			if(topA < 0) { cout << "Exception! Empty Stack!" << endl; return; }
			topA -= 3;
		}
		else if( c == 'B') { 
			if(topB < 0) { cout << "Exception! Empty Stack!" << endl; return; }
			topB -= 3;
		}
		else if( c == 'C') { 
			if(topC < 0) { cout << "Exception! Empty Stack!" << endl; return; }
			topC -= 3;
		}
	}
private:
	int array[100000];
	int topA, topB, topC;
};

int main() {
	return 0;
}