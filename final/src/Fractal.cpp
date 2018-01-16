//============================================================================
// Name        : Fractal.cpp
// Author      : Chenguang Yang

// Description : Udemy Project
//============================================================================

#include <iostream>
#include <cstdint>
#include "Bitmap.h"
#include "Mandelbrot.h"
using namespace std;
using namespace udemy;

int main() {
	const int WIDTH = 800;
	const int HEIGHT = 600;

	int colorMax = -1;
	int colorMin = 256;

	Bitmap testPic(WIDTH, HEIGHT);
	for (int x = 0; x < WIDTH; x++) {
		for (int y = 0; y < HEIGHT; y++) {
//			double xRescale = (x - WIDTH/2) * 2.0 / WIDTH;  // original ratio
//			double xRescale = (x - WIDTH/2) * 2.0 / HEIGHT;  // 1:1 ratio
			double xRescale = (x - WIDTH/2 - 100) * 2.0 / HEIGHT;  // horizontal shift
			double yRescale = (y - HEIGHT/2) * 2.0 / HEIGHT;
			int iter = Mandelbrot::getIteration(xRescale, yRescale);

//			uint8_t color = (uint8_t)(255 * (double)iter / Mandelbrot::MAX_ITER);  // MAX_ITER will be 255
			uint8_t color = (uint8_t)(256 * (double)iter / Mandelbrot::MAX_ITER);  // MAX_ITER will be 0

			if (color > colorMax) colorMax = color;
			if (color < colorMin) colorMin = color;

			testPic.setPixel(x, y, 0, color, 0);
		}
	}
	cout << colorMin << ' ' << colorMax << endl;
	testPic.write("test.bmp");

	cout << "!!!Finish!!!" << endl;
	return 0;
}
