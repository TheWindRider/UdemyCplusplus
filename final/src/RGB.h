/*
 * RGB.h
 *
 *  Created on: Jan 31, 2018
 *      Author: Chenguang
 */

#ifndef RGB_H_
#define RGB_H_

namespace udemy {

struct RGB {
	double red;
	double green;
	double blue;
	RGB(double r, double g, double b);
	virtual ~RGB();
};

RGB operator+(const RGB& first, const RGB& second);
RGB operator-(const RGB& first, const RGB& second);
RGB operator*(const RGB& target, double scaler);
} /* namespace udemy */

#endif /* RGB_H_ */
