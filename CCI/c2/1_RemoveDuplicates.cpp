#include <iostream>
#include <set>
using namespace std;

class node {
	public:
		node(int x) {
			this->elem = x;
			this->next = NULL;
		}
		~node(){};
		int elem;
		node *next;
};

void printList(node *head) {
	while(head != NULL) {
		cout << head->elem << "->";
		head = head->next;
	}
	cout << "NULL" << endl;
}

/*
	Time: O(n)
	Space: O(n) - HashSet
*/
void removeDups(node *head) {
	set<int> buff;

	if(head != NULL) buff.insert(head->elem);

	while(head != NULL ) {
		if(head->next == NULL) return;

		if(buff.find(head->next->elem) == buff.end() ) { // Check if element is in the hash - O(1)
			buff.insert(head->next->elem);
			head = head->next;	
		} else { // Delete node
			node *aux = head->next;
			head->next = head->next->next;

			delete aux;
		}
	}
}

/*
	Time: O(n²)
	Space: O(1) - No extra space
*/
void removeDups2(node *head) {
	node *p = head;
	while( p != NULL ) {
		node *q = p;
		while( q->next != NULL ) {
			if(q->next->elem == p->elem) {
				node *aux = q->next;
				q->next = q->next->next;

				delete aux;
			}
			q = q->next;
		}
		p = p->next;
	}
}

int main() {
	node *head = new node(1);
	node *pointer = head;

	pointer->next = new node(2); pointer = pointer->next;
	pointer->next = new node(3); pointer = pointer->next;
	pointer->next = new node(4); pointer = pointer->next;
	pointer->next = new node(5); pointer = pointer->next;
	pointer->next = new node(4); pointer = pointer->next;
	pointer->next = new node(3); pointer = pointer->next;
	pointer->next = new node(2); pointer = pointer->next;
	pointer->next = new node(0); pointer = pointer->next;

	printList(head);
	removeDups2(head);
	printList(head);

	return 0;
}