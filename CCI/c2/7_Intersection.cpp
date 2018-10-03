#include "linked_list.h"
using namespace std;

int sizeLinkedList(node *head) {
	int size;
	for(size = 0; head != NULL; size++, head = head->next);
	return size;
}

node *intersection(node *x, node *y) {
	int sizeX = sizeLinkedList(x), sizeY = sizeLinkedList(y);
	for(int diff = sizeX - sizeY; diff > 0; diff--, x = x->next);
	for(int diff = sizeY - sizeX; diff > 0; diff--, y = y->next);
	while(x != y) {
		x = x->next;
		y = y->next;
	}
	return x;
}

int main() {
	node *x = new node(1);
	node *pointer = x, *inter;

	pointer->next = new node(2); pointer = pointer->next;
	pointer->next = new node(3); pointer = pointer->next;
	pointer->next = new node(4); pointer = pointer->next;
	inter = pointer->next = new node(5); pointer = pointer->next;
	pointer->next = new node(6); pointer = pointer->next;
	pointer->next = new node(7); pointer = pointer->next;
	pointer->next = new node(8); pointer = pointer->next;

	node *y = new node(10);
	pointer = y;

	pointer->next = new node(9); pointer = pointer->next;
	pointer->next = new node(8); pointer = pointer->next;
	pointer->next = new node(7); pointer = pointer->next;
	pointer->next = new node(6); pointer->next->next = inter;

	node *z = new node(90);
	
	printList(x);
	printList(y);	
	cout << ( (intersection(x,y) == NULL) ? 0 : intersection(x,y)->elem ) << endl << endl;

	printList(x);
	printList(z);	
	cout << ( (intersection(x,z) == NULL) ? 0 : intersection(x,y)->elem ) << endl << endl;
	
	printList(y);
	printList(z);	
	cout << ( (intersection(y,z) == NULL) ? 0 : intersection(x,y)->elem ) << endl << endl;
	

	node *a = new node(10);
	pointer = a;

	pointer->next = new node(9); pointer = pointer->next;
	pointer->next = new node(8); pointer = pointer->next;
	pointer->next = new node(7); pointer = pointer->next;
	pointer->next = new node(6);

	node *b = new node(1);
	pointer = b;

	pointer->next = new node(2); pointer = pointer->next;
	pointer->next = new node(3); pointer = pointer->next;
	pointer->next = new node(4); pointer = pointer->next;
	pointer->next = new node(5);

	printList(a);
	printList(b);	
	cout << ( (intersection(a,b) == NULL) ? 0 : intersection(x,y)->elem ) << endl << endl;
	return 0;
}
