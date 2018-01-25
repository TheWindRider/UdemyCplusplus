/*
 * Fractal.h
 *
 *  Created on: Jan 21, 2018
 *      Author: Chenguang
 */

#ifndef FRACTAL_H_
#define FRACTAL_H_

#include <memory>
#include "Bitmap.h"
#include "ZoomList.h"
using namespace std;

namespace udemy {

class Fractal {
private:
	int m_width{0};
	int m_height{0};
	unique_ptr<int[]> histIteration;
	unique_ptr<int[]> cumlIteration;
	unique_ptr<int[]> fractal;
	ZoomList v_zooms;
	Bitmap fractalImg;
public:
	Fractal(int width, int height);
	void addZoom(const Zoom& one_zoom);
	void calcIteration();
	void drawPixel();
	void writeBitmpa(string filename);
	virtual ~Fractal();
};

} /* namespace udemy */

#endif /* FRACTAL_H_ */
