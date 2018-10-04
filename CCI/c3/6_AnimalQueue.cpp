#include <iostream>
using namespace std;

/*
	Add a field age of the animal.
*/
class animal {
public:
	animal(string name, int age) {
		this->name = name;
		this->age = age;
	}
	string name;
}

class specialQueue {
public:
	void enqueue(string name, string type) {
		if(type.compare("cat") == 0 ) { cats.push( new node(name,age) ); }
		else { dogs.push( new node(name,age) ); }
	}
	void dequeue() {
		if(cats.isEmpty() && dogs.isEmpty() ) { cout << "Exception! Empty Stack" << endl; return; }
		else if(cats.isEmpty() && !dogs.isEmpty() ) { dogs.pop(); return; } 
		else if(!cats.isEmpty() && dogs.isEmpty() ) { cats.pop(); return; }
		
		if(cats.front().age < dogs.front().age ) cats.pop();
		else dogs.pop();
	}
	void dequeueCat() {
		if(cats.isEmpty() ) { cout << "Exception! Empty Stack" << endl; return; }
		cats.pop();
	}
	void dequeueDog() {
		if(dogs.isEmpty() ) { cout << "Exception! Empty Stack" << endl; return; }
		dogs.pop();
	}
private:
	queue<animal> cats, dogs;
}