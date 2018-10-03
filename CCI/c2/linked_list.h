#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class node {
	public:
		node(int x) {
			this->elem = x;
			this->next = NULL;
		}
		int elem;
		node *next;
};

node *createLinkedList( int v[], int size) {
	if(size == 0) return NULL;

	node *head = new node(v[0]);
	node *pointer = head;

	for(int i = 1; i < size; i++) {
		pointer->next = new node(v[i]); 
		pointer = pointer->next;
	}
	return head;
}

void printNode(node *x) {
	if(x == NULL ) cout << "NULL" << endl;
	else cout << x->elem << "**" << endl;
}

void printList(node *head) {
	while(head != NULL) {
		cout << std::setw(3) << head->elem << " -> ";
		head = head->next;
	}
	cout << "NULL" << endl;
}