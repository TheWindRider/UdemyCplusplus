/*
 * Map&Set.cpp
 *
 *  Created on: Nov 17, 2017
 *      Author: frankycg
 */

#include <iostream>
#include <map>
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
	Person(const Person &another) {
		name = another.name;
		age = another.age;
//		cout << "Copy constructor" << endl;
	}
	/* const if used as key in map */
	void print() const {
		cout << name << " is " << age << " years old. ";
	}
	/* Overload < so can be used as key in map */
	bool operator<(const Person &another) const {
		return name < another.name;
	}
};

int main() {
	map<int, Person> person_age;
	person_age[2] = Person("Mike", 40);
	person_age[8] = Person("Vicky", 20);
	person_age[5] = Person("Raj", 30);

	map<Person, int> person_age_r;
	person_age_r[Person("Mike", 40)] = 2;
	person_age_r[Person("Vicky", 20)] = 8;
	person_age_r[Person("Raj", 30)] = 5;
	/* This will update value of previous key, because the key is evaluated as same */
	person_age_r[Person("Raj", 35)] = 6;

	multimap<int, Person> person_age_m;

	/* This operation will automatically fill in for new key */
	person_age[1].print();
	cout << endl;
	/* So a better way to find key-value pair */
	if (person_age.find(4) == person_age.end()) {
		cout << "Person #4 not found" << endl;
	}
	else {
		cout << "Person #4 found" << endl;
	}
	/* And another way to insert key-value pair */
	person_age.insert(make_pair(4, Person("Peter", 100)));
	/* For multimap, [] insert won't work */
	person_age_m.insert(make_pair(2, Person("Mike", 40)));
	person_age_m.insert(make_pair(8, Person("Vickey", 20)));
	person_age_m.insert(make_pair(5, Person("Raj", 30)));
	person_age_m.insert(make_pair(5, Person("Raj", 35)));
	/* Find a range of key-value pair, range is applicable because multimap is also ordered */
	pair<multimap<int, Person>::iterator, multimap<int, Person>::iterator> it_pair =
			person_age_m.equal_range(5);

	/* Map will reorder by keys */
	for (map<int, Person>::iterator it = person_age.begin(); it != person_age.end(); it++) {
		cout << it -> first << ": " << flush;
		it -> second.print();
		cout << " | ";
		/* Another way to dispay key-value pair */
		pair<int, Person> age = *it;
		cout << age.first << ": " << flush;
		age.second.print();
		cout << endl;
	}
	for (map<Person, int>::iterator it = person_age_r.begin(); it != person_age_r.end(); it++) {
		cout << it -> second << ": " << flush;
		it -> first.print();
		cout << endl;
	}
	for (map<int, Person>::iterator it = it_pair.first; it != it_pair.second; it++) {
		cout << it -> first << ": " << flush;
		it -> second.print();
		cout << endl;
	}
	return 0;
}
