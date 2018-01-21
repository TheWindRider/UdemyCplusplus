/*
 * Zoom.h
 *
 *  Created on: Jan 19, 2018
 *      Author: Chenguang
 */

#ifndef ZOOM_H_
#define ZOOM_H_

namespace udemy {

struct Zoom {
	int x{0};
	int y{0};
	double scale{0.0};
	Zoom(int x_coord, int y_coord, double scale): x(x_coord), y(y_coord), scale(scale) {};
};

} /* namespace udemy */

#endif /* ZOOM_H_ */
