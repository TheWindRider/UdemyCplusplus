/*
 * RGB.cpp
 *
 *  Created on: Jan 31, 2018
 *      Author: Chenguang
 */

#include "RGB.h"

namespace udemy {

RGB::RGB(double r, double g, double b): red(r), green(g), blue(b) {
	// TODO Auto-generated constructor stub

}

RGB operator+(const RGB& first, const RGB& second) {
	double sum_red = first.red + second.red;
	double sum_green = first.green + second.green;
	double sum_blue = first.blue + second.blue;
	return RGB(sum_red, sum_green, sum_blue);
}
RGB operator-(const RGB& first, const RGB& second) {
	double diff_red = first.red - second.red;
	double diff_green = first.green - second.green;
	double diff_blue = first.blue - second.blue;
	return RGB(diff_red, diff_green, diff_blue);
}
RGB operator*(const RGB& target, double scaler) {
	double new_red = target.red * scaler;
	double new_green = target.green * scaler;
	double new_blue = target.blue * scaler;
	return RGB(new_red, new_green, new_blue);
}

RGB::~RGB() {
	// TODO Auto-generated destructor stub
}

} /* namespace udemy */
