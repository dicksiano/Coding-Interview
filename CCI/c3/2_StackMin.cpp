#include <iostream>
#include <stack>
using namespace std;

/*
	The idea is know to each element who was the minimum when that element
	was pushed into the stack. So, each node has a field min to save that info
*/
class node {
public:
	node(int x, int y) {
		this->elem = x;
		this->min = y;
		this->next = NULL;
	}
	int elem, min;
	node *next;
};

class stackMin {
public:
	void push(int x) {
		if(s.empty()) s.push( new node(x,x) );
		else s.push( new node(x, min(x,s.top()->min) ) );
	}
	int top() {
		if(s.empty()) { cout << "Exception! Empty Stack!" << endl; return 0; }
		else return s.top()->elem;
	}
	void pop() {
		if(s.empty()) cout << "Exception! Empty Stack!" << endl;
		else s.pop();
	}
	int mini() { return s.top()->min; }
private:
	stack<node*> s;
};

int main() {
	stackMin s;

	s.push(3);
	int aux = s.top();
	if(aux) cout << "Top: " << aux << endl;
	cout << s.mini() << endl << endl;

	s.push(6);
	aux = s.top();
	if(aux) cout << "Top: " << aux << endl;
	cout << s.mini() << endl << endl;


	s.push(2);
	aux = s.top();
	if(aux) cout << "Top: " << aux << endl;
	cout << s.mini() << endl << endl;

	s.pop();
	aux = s.top();
	if(aux) cout << "Top: " << aux << endl;
	cout << s.mini() << endl << endl;


	s.push(8);
	aux = s.top();
	if(aux) cout << "Top: " << aux << endl;
	cout << s.mini() << endl << endl;

	s.push(9);
	aux = s.top();
	if(aux) cout << "Top: " << aux << endl;
	cout << s.mini() << endl << endl;


	s.push(1);
	aux = s.top();
	if(aux) cout << "Top: " << aux << endl;
	cout << s.mini() << endl << endl;

	return 0;
}