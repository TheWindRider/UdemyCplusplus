//============================================================================
// Name        : Fractal.cpp
// Author      : Chenguang Yang

// Description : Udemy Project
//============================================================================

#include <iostream>
#include "Bitmap.h"
using namespace std;
using namespace udemy;

int main() {
	const int WIDTH = 800;
	const int HEIGHT = 600;

	Bitmap testPic(WIDTH, HEIGHT);
	for (int x = 0; x < WIDTH/2; x++) {
		for (int y = 0; y < HEIGHT/2; y++) {
			testPic.setPixel(x, y, 0, 255, 0);
		}
	}
	testPic.write("test.bmp");

	cout << "!!!Finish!!!" << endl;
	return 0;
}
