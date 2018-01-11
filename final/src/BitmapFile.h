#ifndef BITMAPFILE_H_
#define BITMAPFILE_H_

#include <cstdint>
using namespace std;

#pragma pack(2)
struct BitmapFile {
	char header[2]{'B', 'M'};
	int32_t fileSize;
	int32_t reserved{0};
	int32_t dataOffset;
};

#endif /* BITMAPFILE_H_*/
