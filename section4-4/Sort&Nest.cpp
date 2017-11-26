/*
 * Sort&Nest.cpp
 *
 *  Created on: Nov 21, 2017
 *      Author: frankycg
 */

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
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
	void print() const {
		cout << name << " is " << age << " years old. " << endl;
	}
	/* Overload < so can be sorted in vector */
	bool operator<(const Person &another) const {
		return name < another.name;
	}
	/* Access to private fields of this class */
	friend bool customComp(const Person &one, const Person &another);
};

/* Another way Person objects can be sorted */
bool customComp(const Person &one, const Person &another) {
	return one.age < another.age;
}

int main() {
	vector<Person> people;
	map<string, vector<int> > scores;

	people.push_back(Person("Mike", 40));
	people.push_back(Person("Vicky", 20));
	people.push_back(Person("Raj", 30));
	people.push_back(Person("Sue", 10));
	scores["Vickey"].push_back(65);
	scores["Vickey"].push_back(91);
	scores["Mike"].push_back(83);
	scores["Mike"].push_back(72);
	scores["Mike"].push_back(98);

	/* sort by default < overload, by name */
	sort(people.begin(), people.end());
	for (int i = 0; i < people.size(); i++) {
		people[i].print();
	}
	/* sort by custom compare function, by age */
	sort(people.begin(), people.end(), customComp);
	for (int i = 0; i < people.size(); i++) {
		people[i].print();
	}

	for (map<string, vector<int> >::iterator it = scores.begin(); it != scores.end(); it++) {
		/* My error was "...it < scores.end()..." */
		string name = it -> first;
		/* local var name same as global, local will be used, which is what we want */
		vector<int> scores = it -> second;
		cout << name << ": " << flush;
		for (int i = 0; i < scores.size(); i++) {
			cout << scores[i] << ' ' << flush;
		}
		cout << endl;
	}
	return 0;
}
