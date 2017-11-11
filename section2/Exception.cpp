/*
 * Exception.cpp
 *
 *  Created on: Nov 10, 2017
 *      Author: frankycg
 */

#include <iostream>
#include <exception>
using namespace std;

class MyException: public exception {
public:
	/* customize exception in a child class of exception */
	virtual const char* what() const throw() {
		return "Customized error message";
	}
};
class MightGoWrong {
public:
	MightGoWrong() {
		/* a standard exception will be thrown */
		char *pMemory = new char[999999999999999];
		delete []pMemory;
	}
};

void mightGoWrong() {
	bool error1 = false;
	bool error2 = true;
	/* primitive exception */
	if (error1) {
		throw "Error Code = 8";
	}
	if (error2) {
		/* note catch clause associated with object */
		throw string("Error Code = 9");
	}
}
void riskyAction() {
	/* whenever exception, program returns to top of stack */
	throw MyException();
	MightGoWrong errorObject;
	mightGoWrong();
	/* so this output won't be there if any exception before */
	cout << "Risky action continue" << endl;
}

int main() {
	try {
		riskyAction();
	}
	catch (int code) {
		cout << "Error code: " << code << endl;
	}
	catch (char const *msg) {
		cout << "Error message: " << msg << endl;
	}
	/* use reference & for object */
	catch (string &e) {
		cout << "Error message: " << e << endl;
	}
	catch (bad_alloc &e) {
		cout << e.what() << endl;
	}
	/* exception will be caught by preceding parent exception */
//	catch (exception &e) {
//			cout << "Caught by exception: " << e.what() << endl;
//	}
	catch (MyException &e) {
		cout << e.what() << endl;
	}
	/* after exception caught, program continues */
	cout << "Main function continue" << endl;
	return 0;
}
