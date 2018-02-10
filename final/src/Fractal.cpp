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
#include "RGB.h"
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

void Fractal::addRange(double rangeEnd, const RGB& colorEnd, bool firstRange) {
	milestone_range.push_back(Mandelbrot::MAX_ITER * rangeEnd);
	milestone_color.push_back(colorEnd);
	if (!firstRange) {
		milestone_pixel.push_back(0);
	}
}
int Fractal::getRange(int iterations) const {
	int range = 0;
	for (int i = 1; i < milestone_range.size(); i++) {
		range = i;
		if (milestone_range[i] > iterations) break;
	}
	range -= 1;
	return range;
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
	/* sanity check
	cout << "Total 2: " << cumlIteration[Mandelbrot::MAX_ITER - 1] << endl;
	*/
}

void Fractal::calcRangePixel() {
	int rangeIndex = 0;
	for (int i = 1; i < Mandelbrot::MAX_ITER; i++) {
		if (i >= milestone_range[rangeIndex + 1]) {
			rangeIndex += 1;
		}
		milestone_pixel[rangeIndex] += histIteration[i];
	}
	/* sanity check
	int total_pixel = 0;
	for (int value : milestone_pixel) {
		cout << value << endl;
		total_pixel += value;
	}
	cout << "Total 1: " << total_pixel << endl;
	*/
}

void Fractal::drawPixel() {
	RGB start(0, 0, 255);
	RGB end(0, 255, 0);
	for (int x = 0; x < m_width; x++) {
		for (int y = 0; y < m_height; y++) {
			int iter = fractal[y * m_width + x];
			double hue = 0.0;  // hue value for MAX_ITER
			if (iter < Mandelbrot::MAX_ITER) {
				hue = (double) cumlIteration[iter] / cumlIteration[Mandelbrot::MAX_ITER - 1];
			}
			RGB curr = (end - start) * hue + start;
			fractalImg.setPixel(x, y, curr.red, curr.green, curr.blue);
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
