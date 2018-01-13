/*
 * Bitmap.cpp
 *
 *  Created on: Jan 8, 2018
 *      Author: Chenguang
 */

#include <fstream>
#include "Bitmap.h"
#include "BitmapFile.h"
#include "BitmapInfo.h"
using namespace std;
using namespace udemy;

namespace udemy {

Bitmap::Bitmap(int width, int height):
		/* pixel array size is num of pixels * num of color channels */
		m_width(width), m_height(height), m_pPixels(new uint8_t[width*height*3]{}) {
	// TODO Auto-generated constructor stub

}

bool Bitmap:: write(string fileName) {
	BitmapFile fileHeader;
	BitmapInfo infoHeader;

	fileHeader.fileSize = sizeof(BitmapFile) + sizeof(BitmapInfo) + m_width * m_height * 3;
	fileHeader.dataOffset = sizeof(BitmapFile) + sizeof(BitmapInfo);
	infoHeader.width = m_width;
	infoHeader.height = m_height;

	ofstream outFile;
	outFile.open(fileName, ios::out|ios::binary);
	if (!outFile) return false;

	outFile.write((char *)&fileHeader, sizeof(BitmapFile));
	outFile.write((char *)&infoHeader, sizeof(BitmapInfo));
	outFile.write((char *)m_pPixels.get(), m_width * m_height * 3);  // unique_ptr -> normal ptr -> char *

	outFile.close();
	if (!outFile) return false;
	return true;
}
void Bitmap:: setPixel(int x, int y, int8_t red, int8_t green, int8_t blue) {
	uint8_t *pPixel = m_pPixels.get();
	pPixel += (y * m_width + x) * 3;
	pPixel[0] = blue;
	pPixel[1] = green;
	pPixel[2] = red;
}

Bitmap::~Bitmap() {
	// TODO Auto-generated destructor stub
}

} /* namespace udemy */
