/*
 * Bitmap.h
 *
 *  Created on: Jan 8, 2018
 *      Author: Chenguang
 */

#ifndef BITMAP_H_
#define BITMAP_H_

#include <string>
#include <cstdint>
using namespace std;

namespace udemy {

class Bitmap {
private:
	int m_width{0};
	int m_height{0};
public:
	Bitmap(int width, int height);
	bool write(string fileName);
	void setPixel(int x, int y, int8_t red, int8_t green, int8_t blue);
	virtual ~Bitmap();
};

} /* namespace udemy */

#endif /* BITMAP_H_ */
