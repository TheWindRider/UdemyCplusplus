//============================================================================
// Name        : Constructor.cpp
// Author      : Chenguang Yang

// Description : Udemy exercise
//============================================================================

#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

class Person {
	int age;
	int *_pObject;
	string greeting;
	static const int SIZE = 10;
public:
	/* New in C++11: Constructor Delegation */
	Person(): Person(0, "Hello World!") {
		cout << "Constructor without parameters" << endl;
	}
	Person(int value, string text) {
		this -> age = value;
		this -> greeting = text;
		this -> _pObject = new int[SIZE]{};  // allocate memory
		cout << "Constructor with parameters" << endl;
	}
	~Person() {
		delete []_pObject;  // recycle memory
		cout << "Tombstone: Age=" << this -> age << "; Greeting=" << this -> greeting << endl;
	}
	Person(const Person &another) {
		this -> age = another.age;
		this -> greeting = another.greeting;
		this -> _pObject = new int[SIZE]{};  // default copy constructor not a good idea for pointer
		memcpy(_pObject, another._pObject, SIZE*sizeof(int));
		cout << "Copy Constructor" << endl;
	}
	Person &operator=(const Person &someone) {
		this -> age = someone.age;
		this -> greeting = someone.greeting;
		this -> _pObject = new int[SIZE]{};
		memcpy(_pObject, someone._pObject, SIZE*sizeof(int));
		cout << "Assignment" << endl;
	}
};
int main() {
	Person newBorn;
	cout << "Baby created" << endl;
	vector<Person> people;
	cout << "A vector of person created" << endl;
	people.push_back(Person(60, "Well..."));
	cout << "Add an old person" << endl;
	people.push_back(Person(10, "Hey!"));
	cout << "Add a kid" << endl;
	people[0] = newBorn;
	cout << "Let old person be baby" << endl;
	return 0;
}
