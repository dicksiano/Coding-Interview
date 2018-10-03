#include "linked_list.h"
using namespace std;

/*
	Time: O(n)
	Space: O(n)

	Both optimal, since you have to pass through all elements.
*/
node* partition(node *head, int x) {
	if(head == NULL) return NULL;

	node *left = NULL;
	node *right = NULL;
	node *pLeft, *pRight, *pointer = head;

	while( pointer != NULL ) {
		if(pointer->elem < x) {
			if(left == NULL) left = pLeft = new node(pointer->elem);
			else {
				pLeft->next = new node(pointer->elem);
				pLeft = pLeft->next;
			}
			pLeft->next = NULL;
		}
		else {
			if(right == NULL) right = pRight = new node(pointer->elem);
			else {
				pRight->next = new node(pointer->elem);
				pRight = pRight->next;
			}
			pRight->next = NULL;
		}
		pointer = pointer->next;
	}
	pLeft->next = right;
	return left;
}

int main() {
	int v[] = {1, 23, 3, 45, 5, 71, 7, 1, 9, 3, 30, 5, 2};	
	node *head = createLinkedList(v, 13);

	printList(head);
	printList( partition(head,5) );
	return 0;
}