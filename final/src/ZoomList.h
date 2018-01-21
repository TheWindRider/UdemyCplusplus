/*
 * ZoomList.h
 *
 *  Created on: Jan 20, 2018
 *      Author: Chenguang
 */

#ifndef ZOOMLIST_H_
#define ZOOMLIST_H_

#include <vector>
#include "Zoom.h"
using namespace std;

namespace udemy {

class ZoomList {
private:
	int m_width{0};
	int m_height{0};
	double m_xCenter{0.0};
	double m_yCenter{0.0};
	double m_scale{1.0};
	vector<Zoom> zooms;
public:
	ZoomList(int width, int height): m_width(width), m_height(height) {};
	void add(const Zoom& zoom) {
		zooms.push_back(zoom);
		m_scale *= zoom.scale;
		m_xCenter += (zoom.x - m_width/2) * m_scale;
		m_yCenter += (zoom.y - m_height/2) * m_scale;

		cout << '(' << m_xCenter << ',' << m_yCenter << ')' << " * " << m_scale << endl;
	};
	pair<double, double> doZoom(int x, int y) {
		double xFractal = (x - m_width/2) * m_scale + m_xCenter;
		double yFractal = (y - m_height/2) * m_scale + m_yCenter;
		return pair<double, double>(xFractal, yFractal);
	};
};

} /* namespace udemy */

#endif /* ZOOMLIST_H_ */
