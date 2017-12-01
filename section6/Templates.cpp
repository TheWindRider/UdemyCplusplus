/*
 * Templates.cpp
 *
 *  Created on: Nov 29, 2017
 *      Author: frankycg
 */

#include <iostream>

using namespace std;

void print(int number) {
    cout << "NonTemplate with Param" << endl;
    cout << '[' << number << ", " << int() << ']' << endl;
}

template<class T>
void print(T stuff) {
    cout << "Template with Param" << endl;
    cout << '[' << stuff << ", " << T() << ']' << endl;
}

template<typename T> // either class or typename works
void print2() {
    cout << "Template without Param" << endl;
    cout << '[' << T() << ']' << endl;
}

int main()
{
    print<int>(5);
    print<string>("Hello");
    print2<int>();
    print2<string>();
//    print2(); // Complier don't know the class to compile T()
    print(5); // Compiler will prioritize to associate with the NonTemplate
    print("Hello"); // This one causes program exit at T()

    return 0;
}


