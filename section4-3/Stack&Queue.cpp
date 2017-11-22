/*
 * Stack&Queue.cpp
 *
 *  Created on: Nov 20, 2017
 *      Author: frankycg
 */

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Person {
private:
	string name;
	int age;
public:
	Person(string name, int age):
		name(name), age(age) {
//		cout << "Parameterized constructor" << endl;
	}
	Person():
		name(""), age(0) {
//		cout << "Blank constructor" << endl;
	}
	~Person() {
		cout << "Destroy -> " << flush;
		print();
	}
	Person(const Person &another) {
		name = another.name;
		age = another.age;
//		cout << "Copy constructor" << endl;
	}
	void print() const {
		cout << name << " is " << age << " years old. " << endl;
	}
};

int main() {
	stack<Person> pplStack;
	queue<Person> pplQueue;
	/* Same insert method push() for both type */
	pplStack.push(Person("Mike", 40));
	pplStack.push(Person("Vicky", 20));
	pplStack.push(Person("Raj", 30));
	pplQueue.push(Person("Mike", 40));
	pplQueue.push(Person("Vicky", 20));
	pplQueue.push(Person("Raj", 30));

	/* Same remove method pop() for both type */
	while(pplStack.size() > 0) { // FILO
		/* Stack uses top() */
		Person &currPerson = pplStack.top();
		/* Using a reference so pop() has to come after print() */
		currPerson.print();
		pplStack.pop();
	}
	while(pplQueue.size() > 0) { // FIFO
		/* Queue uses front() */
		Person &currPerson = pplQueue.front();
		currPerson.print();
		pplQueue.pop();
	}
	return 0;
}
