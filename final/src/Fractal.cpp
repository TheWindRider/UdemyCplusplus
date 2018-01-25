/*
 * Fractal.cpp
 *
 *  Created on: Jan 21, 2018
 *      Author: Chenguang
 */

#include <iostream>
#include <cstdint>
#include <math.h>
#include "Fractal.h"
#include "Mandelbrot.h"
using namespace std;

namespace udemy {

Fractal::Fractal(int width, int height): m_width(width), m_height(height),
		histIteration(new int[Mandelbrot::MAX_ITER]{0}),
		cumlIteration(new int[Mandelbrot::MAX_ITER]{0}),
		fractal(new int[m_width * m_height]{0}), v_zooms(width, height), fractalImg(width, height) {
	// TODO Auto-generated constructor stub
}

void Fractal::addZoom(const Zoom& one_zoom) {
	v_zooms.add(one_zoom);
}

void Fractal::calcIteration() {
	for (int x = 0; x < m_width; x++) {
		for (int y = 0; y < m_height; y++) {
			pair<double, double> coord = v_zooms.doZoom(x, y);
			int iter = Mandelbrot::getIteration(coord.first, coord.second);

			fractal[y * m_width + x] = iter;
			/* ignore MAX_ITER, smooth histIteration distribution */
			if (iter == Mandelbrot::MAX_ITER) continue;
			histIteration[iter] += 1;
		}
	}
	/* A cumulative distribution for color palette */
	cumlIteration[0] = histIteration[0];
	for (int i = 1; i < Mandelbrot::MAX_ITER; i++) {
		cumlIteration[i] = cumlIteration[i-1] + histIteration[i];
	}
}

void Fractal::drawPixel() {
	for (int x = 0; x < m_width; x++) {
		for (int y = 0; y < m_height; y++) {
			int iter = fractal[y * m_width + x];
			double hue = 0.0;  // hue value for MAX_ITER
			if (iter < Mandelbrot::MAX_ITER) {
				hue = (double) cumlIteration[iter] / cumlIteration[Mandelbrot::MAX_ITER - 1];
			}
			uint8_t red = 0;
			uint8_t green = pow(255, hue);
			uint8_t blue = 0;
			fractalImg.setPixel(x, y, red, green, blue);
		}
	}
}

void Fractal::writeBitmpa(string filename) {
	fractalImg.write(filename);
	cout << "!!!Finish!!!" << endl;
}

Fractal::~Fractal() {
	// TODO Auto-generated destructor stub
}

} /* namespace udemy */
