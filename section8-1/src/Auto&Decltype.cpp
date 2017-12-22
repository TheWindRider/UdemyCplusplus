//============================================================================
// Name        : Auto&Decltype.cpp
// Author      : Chenguang Yang

// Description : Udemy exercise
//============================================================================

#include <iostream>
#include <typeinfo>
using namespace std;

template <class A, class B>
/* specify trailing return types */
auto sumAuto (A valueA, B valueB) -> decltype(valueA + valueB) {
	return valueA + valueB;
}

int main() {
	string greet = "!!Hello World!!"; // c++ string type
	auto greeting = "!!!Hello World!!!"; // auto recognize primitive string
	cout << typeid(greet).name() << " and " << typeid(greeting).name() << endl;
	cout << greeting << endl;

//	cout << sumAuto(greeting, " Your name") << endl;  // unable to resolve data type in this case
	cout << sumAuto(greet, " Your name") << endl;
	cout << sumAuto(greeting, 5) << endl;  // 2 data types are summable, but in a weird way
//	cout << sumAuto(greet, 5) << endl;  // unable to resolve data type in this case
	return 0;
}
