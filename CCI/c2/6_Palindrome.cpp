#include "linked_list.h"
using namespace std;

void reverseLinkedList(node **head) {
	node *prev = NULL;
	node *curr = *head;
	node *next = NULL;

	while(curr != NULL) {
		next = curr -> next;

		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}

node* copyReverseLinkedList(node *head) {
	node *pointer = NULL, *pPrev = NULL;

	while(head != NULL) {
		pointer = new node(head->elem);
		pointer->next = pPrev;
		pPrev = pointer;

		head = head-> next;
	}
	return pointer;
}

bool compareLinkedList( node *x, node *y) {
	for(; x != NULL || y != NULL; x = x->next, y = y->next) {
		if( x == NULL || y == NULL ) return false; // Diferent sizes
		if( x->elem != y->elem ) return false;
	}
	return true;
}

/* 
	Time: O(n)
	Space: O(n) - copy of the list
*/
bool isPalindrome (node * head) {
	printList(head);
	printList(copyReverseLinkedList(head));
	return compareLinkedList( head, copyReverseLinkedList(head) );
}

int main() {
	int v[] = {1,2,3,4,5,4,3,2,0};
	node *head = createLinkedList(v, 9);
	cout << "isPal: " << isPalindrome(head) << endl;
	return 0;
}