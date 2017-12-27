//============================================================================
// Name        : Initialize.cpp
// Author      : Chenguang Yang

// Description : Udemy exercise
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

class EasyList {
public:
	EasyList (initializer_list<string> initString) {
		cout << "Construct with list of strings: " << endl;
		for (auto item : initString) {
			cout << item << ' ' << flush;
		}
	}
	void print(initializer_list<string> outputString) {
		cout << "Output list of strings: " << endl;
		for (auto item : outputString) {
			cout << item << ' ' << flush;
		}
	}
};

int main() {
	int array[]{2, 3, 5, 7, 11};  // no need to specify array length
	for (int i = 0; i < 5; i++) {
		cout << array[i] << ';' << flush;
	}
	cout << endl;

	int *pArray = new int[3]{2, 3, 5};  // need to specify array length
	for (int i = 0; i < 3; i++) {
		cout << pArray[i] << ';' << flush;
	}
	cout << endl;

	vector<string> strings{"Hello", "World", "!!!"};
	for (int i = 0; i < 3; i++) {
		cout << strings[i] << ' ' << flush;
	}
	cout << endl;

	/* Initializer enable similar format */
	EasyList myList{"Initializer", "list", "are", "handy"};
	cout << endl;
	myList.print({"So", "when", "used", "in", "function"});
	cout << endl;
	return 0;
}
