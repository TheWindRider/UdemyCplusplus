/*
 * Overload.cpp
 *
 *  Created on: Nov 23, 2017
 *      Author: frankycg
 */

#include <iostream>
#include "Complex.h"
using namespace std;
using namespace tutorial;

int main()
{
    Complex num1(3, 2);
    Complex num2 = num1;
    num2.print();
    cout << num2 << endl; // same output as print()

    Complex num3(1, 1);
    Complex num4(2, 4);
    /* chain method works because overloaded = returns object reference */
    num4 = num3 = num1;
    cout << num3 << endl;
    cout << num4 << endl;

    cout << 1.7 + *Complex(4.6, 3.5) + num3 << endl;
    cout << 1.7 + *(Complex(4.6, 3.5) + num3) << endl; // tweaking operator precedence
    cout << (num1 == num2) << endl;
    cout << (num1 == num3) << endl;

    return 0;
}
