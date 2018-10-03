#include "linked_list.h"
using namespace std;

/* 
	Time: O(n)
	Space: O(1)
*/
node *findBegin(node *head) {
	if(head == NULL) return NULL;
	if(head->next == NULL) return NULL;

	node *slow = head->next;
	node *fast = head->next->next;

	while(fast != NULL && fast->next != NULL && slow != fast) {
		slow = slow->next;
		fast = fast->next->next;
	}

	if(fast == NULL) return NULL;
	if(fast->next == NULL) return NULL;
	
	slow = head;
	while(slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

int main() {
	node *head = new node(1);
	node *pointer = head, *cycle;

	pointer->next = new node(2); pointer = pointer->next;
	pointer->next = new node(3); pointer = pointer->next;
	pointer->next = new node(4); pointer = pointer->next;
	pointer->next = new node(5); pointer = pointer->next;
	cycle = pointer->next = new node(6); pointer = pointer->next;
	pointer->next = new node(7); pointer = pointer->next;
	pointer->next = new node(8); pointer = pointer->next;
	pointer->next = new node(9); pointer->next->next = cycle;

	cout << findBegin(head)->elem << endl;

	return 0;
}