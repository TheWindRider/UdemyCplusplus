/*
 * Mandelbrot.cpp
 *
 *  Created on: Jan 14, 2018
 *      Author: Chenguang
 */

#include <complex>
#include "Mandelbrot.h"
using namespace std;

Mandelbrot::Mandelbrot() {
	// TODO Auto-generated constructor stub

}

Mandelbrot::~Mandelbrot() {
	// TODO Auto-generated destructor stub
}

int Mandelbrot::getIteration(double x, double y) {
	complex<double> z = 0;
	complex<double> c(x, y);
	int iteration = 0;

	while (iteration < MAX_ITER) {
		z = z * z + c;
		if (abs(z) > 2) break;
		iteration += 1;
	}
	return iteration;
}
