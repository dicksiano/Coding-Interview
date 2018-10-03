#include "linked_list.h"
using namespace std;

/* 
	Time: O(m+n)
	Space: O(1)
*/
node *sumListReverse(node *x, node *y) {
	int plusOne = 0, a, b, sum;
	node *pointer = NULL, *head = NULL;

	while( x != NULL || y != NULL || plusOne == 1 ) {
		(x != NULL) ? a = x->elem : a = 0;
		(y != NULL) ? b = y->elem : b = 0;

		sum = a + b + plusOne;
		plusOne = sum / 10;
		
		if(head == NULL) 
			head = pointer = new node(sum%10);
		else {
			pointer->next = new node(sum%10);
			pointer = pointer->next;
		}
		
		if(x != NULL) x = x->next;
		if(y != NULL) y = y->next;
	}
	return head;
}

int main() {
	node *x = new node(1);
	node *pointer = x;

	pointer->next = new node(2); pointer = pointer->next;
	pointer->next = new node(3); pointer = pointer->next;
	
	node *y = new node(7);
	pointer = y;

	pointer->next = new node(9); pointer = pointer->next;
	
	printList(x);
	printList(y);	
	printList(sumListReverse(x,y));
	return 0;
}
