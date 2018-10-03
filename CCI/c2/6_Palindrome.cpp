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

int sizeLinkedList(node *head) {
	int size = 0;
	while(head != NULL) {
		size++;
		head = head->next;
	}
	return size;
}

/* 
	Time: O(n)
	Space: O(n) - copy of the list
*/
bool isPalindrome (node * head) {
	return compareLinkedList( head, copyReverseLinkedList(head) );
}

/*
	Time: O(n)
	Space: O(1) - revert just the second part in place.
*/
bool isPalindromeInPlace(node *head) {
	int size = sizeLinkedList(head), res = 1, i;

	node *p = head, *q, *r, *newHead;
	for (i = 0; i < size/2; i++, p = p->next); // Find middle of the list

	newHead = p->next;
	reverseLinkedList(&newHead);
	
	for(i = 0, q = head, r = newHead; i < size/2; i++, q = q->next, r = r->next)
		if(q->elem  != r->elem) res = 0;
	
	reverseLinkedList(&newHead);
	return res;
}

int main() {
	int v[] = {1,2,3,4,5,4,3,2,0};
	node *head = createLinkedList(v, 9);
	// Help debug!
	printList(head);
	printList(copyReverseLinkedList(head));
	cout << "isPal: " << isPalindrome(head) << endl;
	cout << "isPalInPlace: " << isPalindromeInPlace(head) << endl;
	return 0;
}