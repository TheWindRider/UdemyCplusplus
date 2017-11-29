/*
 * Complex.cpp
 *
 *  Created on: Nov 25, 2017
 *      Author: frankycg
 */

#include "Complex.h"

namespace tutorial {

Complex::Complex():
	real(0), img(0) {
	// TODO Auto-generated constructor stub
}
Complex::Complex(double r, double i):
	real(r), img(i){

}
Complex::Complex(const Complex &another) {
	real = another.real;
	img = 0; //not really copy, just to see different from '='
}
void Complex::print() const {
	cout << '(' << real << ',' << img << "i)" << endl;
}
/* Overload * as conjugation */
Complex Complex::operator*() {
	return Complex(real, -img);
}
/* Overload = instead of default shallow copy */
const Complex & Complex::operator=(const Complex &another) {
	real = another.real;
	img = another.img;
	return *this;
}
/* Overload << to use cout on Person object */
ostream & operator<<(ostream &output, const Complex &another) {
	output << '(' << another.real << ',' << another.img << "i)";
	return output;
}
/* Overload multiple + cases */
Complex operator+(const Complex &one, const Complex &another) {
	double plusReal = one.getReal() + another.getReal();
	double plusImg = one.getImg() + another.getImg();
	return Complex(plusReal, plusImg);
}
Complex operator+(const Complex &one, double real) {
	double plusReal = one.getReal() + real;
	double plusImg = one.getImg();
	return Complex(plusReal, plusImg);
}
Complex operator+(double real, const Complex &another) {
	return operator+(another, real);
}
bool operator==(const Complex &one, const Complex &another) {
	bool equalReal = one.getReal() == another.getReal();
	bool equalImg = one.getImg() == another.getImg();
	return equalReal && equalImg;
}
bool operator!=(const Complex &one, const Complex &another) {
	return !operator==(one, another);
}

} /* namespace tutorial */
