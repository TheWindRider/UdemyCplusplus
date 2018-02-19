//============================================================================
// Name        : Fractal.cpp
// Author      : Chenguang Yang

// Description : Udemy Project
//============================================================================

#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>
#include "Fractal.h"
#include "Zoom.h"
using namespace std;
using namespace udemy;

int main() {
	const int WIDTH = 800;
	const int HEIGHT = 600;

	Fractal fractalPicture(WIDTH, HEIGHT);

	Zoom centerZoom(WIDTH/2, HEIGHT/2, 2.0/HEIGHT);
	fractalPicture.addZoom(centerZoom);
	fractalPicture.addZoom(Zoom(250, 450, 0.3));
	fractalPicture.addZoom(Zoom(325, 425, 0.2));

	fractalPicture.addRange(0.0, RGB(0, 200, 255), true);
	fractalPicture.addRange(0.002, RGB(50, 150, 200));
	fractalPicture.addRange(0.01, RGB(100, 100, 150));
	fractalPicture.addRange(0.1, RGB(150, 50, 50));
	fractalPicture.addRange(1.0, RGB(255, 0, 0));

	fractalPicture.calcIteration();
	fractalPicture.calcRangePixel();
	fractalPicture.drawPixel();
	fractalPicture.writeBitmpa("Mandelbrot.bmp");

	return 0;
}
