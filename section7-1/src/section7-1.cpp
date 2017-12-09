//============================================================================
// Name        : section7-1.cpp
// Author      : Chenguang Yang

// Description : Udemy exercise
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct matchSizeGeneral {
	/* compared against next block of code, this avoids hard-coding */
	int criteriaSize;
	bool operator()(string input) {
		return input.size() == criteriaSize;
	}
};

bool matchSize(string input) {
    return input.size() == 3;
}

bool matchTrend(string before, string after) {
    return after.size() >= before.size();
}

/* note the syntax to use function as parameter */
int my_count_if(vector<string> &strVec, bool (*match)(string first, string second)) {
    int total = 0;
    for (int i = 1; i < strVec.size(); i++) {
        if (matchTrend(strVec[i-1], strVec[i])) {
            total += 1;
        }
    }
    return total;
}

int main()
{
    vector<string> strVec;
    strVec.push_back("one");
    strVec.push_back("two");
    strVec.push_back("three");
    strVec.push_back("four");
    strVec.push_back("five");

    matchSizeGeneral myMatchSize = {4};
    /* using a functor, which looks same as a function */
    cout << count_if(strVec.begin(), strVec.end(), myMatchSize) << endl;

    /* custom criteria */
    cout << count_if(strVec.begin(), strVec.end(), matchSize) << endl; // function name is the pointer
    /* custom criteria and function */
    cout << my_count_if(strVec, matchTrend) << endl;

    return 0;
}
