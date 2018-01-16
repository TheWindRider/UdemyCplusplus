/*
 * Mandelbrot.h
 *
 *  Created on: Jan 14, 2018
 *      Author: Chenguang
 */

#ifndef MANDELBROT_H_
#define MANDELBROT_H_

class Mandelbrot {
public:
	static const int MAX_ITER = 1000;
public:
	Mandelbrot();
	virtual ~Mandelbrot();
	static int getIteration(double x, double y);
};

#endif /* MANDELBROT_H_ */
