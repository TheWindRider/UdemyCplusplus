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

	fractalPicture.calcIteration();
	fractalPicture.drawPixel();
	fractalPicture.writeBitmpa("test.bmp");

	return 0;
}
