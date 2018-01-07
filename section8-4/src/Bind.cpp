//============================================================================
// Name        : Bind.cpp
// Author      : Chenguang Yang

// Description : Udemy exercise
//============================================================================

#include <iostream>
#include <functional>
using namespace std;
using namespace placeholders;

class SimpleMath {
public:
	int arith(int a, int b, int c) {
		cout << a << '+' << b << '-' << c << '=' << endl;
		return a + b - c;
	}
};

int arith(int a, int b, int c) {
	cout << a << '+' << b << '-' << c << '=' << endl;
	return a + b - c;
}
int arith2(function<int(int, int)> inputFunc) {
	return inputFunc(6, 7);
}


int main() {
	auto allNumbers = bind(arith, 2, 3, 4);
	cout << allNumbers() << endl;
	auto allParams = bind(arith, _1, _2, _3);
	cout << allParams(3, 4, 5) << endl;
	// mix-and-match makes this flexible
	auto mixMatch = bind(arith, _2, 10, _1);
	cout << mixMatch(6, 7) << endl;

	SimpleMath easy;
	// bind to a member function in class
	auto memberFunc = bind(&SimpleMath::arith, easy, _2, 10, _1);
	cout << memberFunc(6, 7) << endl;

	cout << arith2(memberFunc) << endl;
	return 0;
}
