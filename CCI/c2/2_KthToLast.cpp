#include <iostream>
using namespace std;

class node {
public:
	node(int x) {
		this->data  = x;
		this->next = NULL;
	}
	int data;
	node *next;
};

void printNode(node *x) {
	if(x == NULL ) cout << "NULL" << endl;
	else cout << x->data << "**" << endl;
}

/* 
	Time: O(n)
	Space: O(1)
*/
node * kthToEnd( node * head, int k) {
	node *slow, *fast;
	slow = fast = head;

	for (int i = 0; i < k; ++i, fast = fast->next) 
		if( fast == NULL ) return NULL;

	if( fast == NULL ) return NULL; // Avoid crash

	while(fast->next != NULL) {
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
int main() {
	node *head = new node(1);
	node *pointer = head;

	pointer->next = new node(2); pointer = pointer->next;
	pointer->next = new node(3); pointer = pointer->next;
	pointer->next = new node(4); pointer = pointer->next;
	pointer->next = new node(5); pointer = pointer->next;
	pointer->next = new node(6); pointer = pointer->next;
	pointer->next = new node(7); pointer = pointer->next;
	pointer->next = new node(8); pointer = pointer->next;
	pointer->next = new node(9); pointer = pointer->next;
	pointer->next = new node(10); pointer = pointer->next;

	printNode(kthToEnd(head,1));
	printNode(kthToEnd(head,2));
	printNode(kthToEnd(head,3));
	printNode(kthToEnd(head,7));
	printNode(kthToEnd(head,8));
	printNode(kthToEnd(head,20));

	return 0;
}