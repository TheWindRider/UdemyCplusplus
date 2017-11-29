/*
 * Complex.h
 *
 *  Created on: Nov 25, 2017
 *      Author: frankycg
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_
#include <iostream>

using namespace std;

namespace tutorial {

class Complex {
private:
	double real;
	double img;
public:
	Complex();
	Complex(double r, double i);
	Complex(const Complex &another);
	void print() const;
	double getReal() const {return real;}; //const make it handy in other places call get()
	double getImg() const {return img;};
	Complex operator*();
	const Complex & operator=(const Complex &another);
	friend ostream & operator<<(ostream &output, const Complex &another);
};

/* with get(), no need to friend these */
Complex operator+(const Complex &one, const Complex &another);
Complex operator+(const Complex &one, double real);
Complex operator+(double real, const Complex &another);
bool operator==(const Complex &one, const Complex &another);
bool operator!=(const Complex &one, const Complex &another);

} /* namespace tutorial */

#endif /* COMPLEX_H_ */
