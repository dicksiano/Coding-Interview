#include <iostream>
#include <queue>
using namespace std;

/* 
	The main challenge is the method PopAt()
	Remenber to bring the end of the next stacks to the top of the others.
*/

void printStack(deque<int> s) {
	while( !s.empty() ) {
		cout << s.back() << endl;
		s.pop_back();
	}
	cout << "empty" << endl << endl;
}

class stackOfPlates {
private:
	vector< deque<int> > s;
	int currIndex;
	int maxi;
public:
	stackOfPlates(int maxi) {
		this->currIndex = 0;
		this->maxi = maxi;
		deque<int> dq;
		s.push_back( dq );
	}
	void push(int x) {
		if(s[currIndex].size() == maxi) {
			currIndex++;
			deque<int> dq;
			s.push_back(dq);
			s[currIndex].push_back(x);
		}
		else
			s[currIndex].push_back(x);
	}
	int top() {
		if(s[currIndex].empty() ) {
			cout << "Empty Stack!" << endl;
			return 0;
		}
		return s[currIndex].back();
	}
	void pop() {
		if(s[currIndex].empty() )
			cout << "Empty Stack!" << endl;
		else {
			s[currIndex].pop_back();
			if(s[currIndex].empty() && currIndex > 0) {
				s.pop_back();
				currIndex--;
			}
		}
	}
	void popAt(int x) {
		if(x > currIndex || x < 0) { 
			cout << "Invalid index!" << endl; 
			return; 
		}
		s[x].pop_back(); // TOMAR CUIDADO! HAVIA COLOCADO ISSO DENTRO DO FOR E TIRAVA VARIOS ELEMENTOS
		for(int	i = x; i < currIndex; i++) {
			s[i].push_back( s[i+1].front() );
			s[i+1].pop_front();
		}
		if(s[currIndex].empty() && currIndex > 0){ 
			currIndex--;
			s.pop_back();
		}
	}
	void printStacks() {
		cout << "Num of Stacks: " << s.size() << endl << endl;

		for( vector< deque<int> >::iterator it = s.begin(); it != s.end(); it++)
			printStack(*it);
	}
};

int main() {
	stackOfPlates s(3);

	for (int i = 0; i < 15; ++i) {
		s.push(i);
		//s.printStacks();
	}
	s.printStacks();

	
	s.popAt(0);
	s.printStacks();

	s.popAt(2);
	s.printStacks();


	s.pop();
	s.pop();
	s.pop();
	
	s.printStacks();
	return 0;
}
