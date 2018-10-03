#include <iostream>
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

/*
	Time: O(n)
	Space: O(1) - In place!
*/
void deleteMiddleNode( node *head ) {
	if(head == NULL) return;
	if(head->next == NULL) return; // CANNOT DELETE LAST ELEMENT!
	while(head->next->next != NULL) {
		head->elem = head->next->elem;
		head = head->next;
	}
	head->elem = head->next->elem;

	node *aux = head->next;
	head->next = NULL;
	delete aux;
}

void printList(node *head) {
	while(head != NULL) {
		cout << head->elem << "->";
		head = head->next;
	}
	cout << "NULL" << endl;
}

int main() {

	node *head = new node(1);
	node *pointer = head, *del;

	pointer->next = new node(2); pointer = pointer->next;
	pointer->next = new node(3); pointer = pointer->next;
	pointer->next = new node(4); pointer = pointer->next;
	del = pointer->next = new node(5); pointer = pointer->next;
	pointer->next = new node(4); pointer = pointer->next;
	pointer->next = new node(3); pointer = pointer->next;
	pointer->next = new node(2); pointer = pointer->next;
	pointer->next = new node(0); pointer = pointer->next;

	printList(head);
	deleteMiddleNode(del);
	printList(head);

	return 0;
}