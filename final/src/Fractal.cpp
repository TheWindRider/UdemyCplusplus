//============================================================================
// Name        : Fractal.cpp
// Author      : Chenguang Yang

// Description : Udemy Project
//============================================================================

#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
using namespace std;
using namespace udemy;

int main() {
	const int WIDTH = 800;
	const int HEIGHT = 600;

	unique_ptr<int[]> histIteration(new int[Mandelbrot::MAX_ITER]{0});
	unique_ptr<int[]> cumlIteration(new int[Mandelbrot::MAX_ITER]{0});
	unique_ptr<int[]> fractal(new int[WIDTH * HEIGHT]{0});

	Bitmap testPic(WIDTH, HEIGHT);
	ZoomList currZoom(WIDTH, HEIGHT);
	Zoom centerZoom(WIDTH/2 - 50, HEIGHT/2, 2.0/HEIGHT);
	currZoom.add(centerZoom);

	for (int x = 0; x < WIDTH; x++) {
		for (int y = 0; y < HEIGHT; y++) {
			pair<double, double> coord = currZoom.doZoom(x, y);
			int iter = Mandelbrot::getIteration(coord.first, coord.second);

			fractal[y * WIDTH + x] = iter;
			/* ignore MAX_ITER, smooth histIteration distribution */
			if (iter == Mandelbrot::MAX_ITER) continue;
			histIteration[iter] += 1;
		}
	}

	/* A cumulative distribution for color palette */
	for (int i = 0; i < Mandelbrot::MAX_ITER; i++) {
		if (i == 0) {
			cumlIteration[i] = histIteration[i];
		}
		else {
			cumlIteration[i] = cumlIteration[i-1] + histIteration[i];
		}
	}
	cout << cumlIteration[Mandelbrot::MAX_ITER - 1] << "; " << WIDTH * HEIGHT << endl;

	for (int x = 0; x < WIDTH; x++) {
		for (int y = 0; y < HEIGHT; y++) {
			int iter = fractal[y * WIDTH + x];
			double hue = 0.0;  // hue value for MAX_ITER
			if (iter < Mandelbrot::MAX_ITER) {
				hue = (double) cumlIteration[iter] / cumlIteration[Mandelbrot::MAX_ITER - 1];
			}
			uint8_t red = 0;
			uint8_t green = pow(255, hue);
			uint8_t blue = 0;
			testPic.setPixel(x, y, red, green, blue);
		}
	}
	testPic.write("test.bmp");

	cout << "!!!Finish!!!" << endl;
	return 0;
}
