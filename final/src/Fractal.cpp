//============================================================================
// Name        : Fractal.cpp
// Author      : Chenguang Yang

// Description : Udemy Project
//============================================================================

#include <iostream>
#include <cstdint>
#include <memory>
#include "Bitmap.h"
#include "Mandelbrot.h"
using namespace std;
using namespace udemy;

int main() {
	const int WIDTH = 800;
	const int HEIGHT = 600;

	unique_ptr<int[]> histIteration(new int[Mandelbrot::MAX_ITER]{0});
	unique_ptr<int[]> cumlIteration(new int[Mandelbrot::MAX_ITER]{0});
	unique_ptr<int[]> fractal(new int[WIDTH * HEIGHT]{0});

	Bitmap testPic(WIDTH, HEIGHT);
	for (int x = 0; x < WIDTH; x++) {
		for (int y = 0; y < HEIGHT; y++) {
//			double xRescale = (x - WIDTH/2) * 2.0 / WIDTH;  // original ratio
//			double xRescale = (x - WIDTH/2) * 2.0 / HEIGHT;  // 1:1 ratio
			double xRescale = (x - WIDTH/2 - 100) * 2.0 / HEIGHT;  // horizontal shift
			double yRescale = (y - HEIGHT/2) * 2.0 / HEIGHT;
			int iter = Mandelbrot::getIteration(xRescale, yRescale);

			fractal[y * WIDTH + x] = iter;
			/* ignore MAX_ITER, smooth histIteration distribution */
			if (iter == Mandelbrot::MAX_ITER) continue;
			histIteration[iter] += 1;
		}
	}

	for (int i = 0; i < Mandelbrot::MAX_ITER; i++) {
		if (i == 0) {
			cumlIteration[i] = histIteration[i];
		}
		else {
			cumlIteration[i] = cumlIteration[i-1] + histIteration[i];
		}
	}

	for (int x = 0; x < WIDTH; x++) {
		for (int y = 0; y < HEIGHT; y++) {
			int iter = fractal[y * WIDTH + x];
			double hue = 1.0;  // hue value for MAX_ITER
			if (iter < Mandelbrot::MAX_ITER) {
				hue = (double) cumlIteration[iter] / cumlIteration[Mandelbrot::MAX_ITER - 1];
			}
			testPic.setPixel(x, y, 0, 255 * hue, 0);
		}
	}
	testPic.write("test.bmp");

	cout << "!!!Finish!!!" << endl;
	return 0;
}
