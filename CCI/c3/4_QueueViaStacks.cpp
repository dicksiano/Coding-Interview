g++#include <iostream>
#include <stack>
using namespace std;

/* 
	Use 2 queues to simulate a stack
*/
class queueViaStacks {
public:
	~queueViaStacks() {
		while(!s.empty() )
			s.pop();
		while(!sAux.empty() )
			sAux.pop();
	}

	void push(int x) {
		while(!s.empty() ) {
			sAux.push( s.top() );
			s.pop();
		}
		s.push(x);
		while(!sAux.empty() ) {
			s.push( sAux.top() );
			sAux.pop();
		}
	}

	void deque() { s.pop(); }

	int front() { return s.top(); }
	
private:
	stack<int> s, sAux;
};

int main() {
	queueViaStacks q;

	for (int i = 0; i < 15; ++i) {
		q.push(i);
	}
	q.push(-1);
	q.push(1281);
	for (int i = 0; i < 17; ++i) {
		cout << q.front() << endl;
		q.deque();
	}
	return 0;
}
