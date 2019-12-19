#include "Surface.h"
#include <cassert>
#include "ChiliWin.h"
#include <fstream>

Surface::Surface(int width, int height)
	:
	width(width),
	height(height),
	ptrPixels(new Color[width*height])
{
}

Surface::Surface(const std::string& filename) {
	std::ifstream file(filename, std::ios::binary);
	BITMAPFILEHEADER bmpFileHeader;
	file.read(reinterpret_cast<char*>(&bmpFileHeader), sizeof(bmpFileHeader));

	BITMAPINFOHEADER bmpInfoHeader;
	file.read(reinterpret_cast<char*>(&bmpInfoHeader), sizeof(bmpInfoHeader));

	assert(bmpInfoHeader.biBitCount == 24);
	assert(bmpInfoHeader.biCompression == BI_RGB);

	width = bmpInfoHeader.biWidth;
	height = bmpInfoHeader.biHeight;

	ptrPixels = new Color[width*height];

	file.seekg(bmpFileHeader.bfOffBits);
	const int padding = (4 - (width * 3) % 4) % 4;

	for(int y=height-1;y>=0;y--) {
		for (int x = 0; x < width; x++) {
			PutPixel(x, y, Color( file.get(),file.get(),file.get()));
		}
		
		file.seekg(padding,std::ios::cur);
	}

}

Surface::Surface(const Surface& rhs)
	:
	Surface(rhs.width,rhs.height)
{
	const int numPixels = width * height;
	for(int i=0;i<numPixels;i++) {
		ptrPixels[i] = rhs.ptrPixels[i];
	}
}

Surface& Surface::operator=(const Surface& rhs) {
	width = rhs.width;
	height = rhs.height;

	delete[] ptrPixels;
	ptrPixels = new Color[width*height];

	const int numPixels = width * height;
	for (int i = 0; i < numPixels; i++) {
		ptrPixels[i] = rhs.ptrPixels[i];
	}
	
	return *this;
}

Surface::~Surface() {
	delete[] ptrPixels;
	ptrPixels = nullptr;
}

void Surface::PutPixel(int x, int y, Color col) {
	assert(x >= 0);
	assert(x < width);
	assert(y >= 0);
	assert(y < height);
	
	ptrPixels[y * width + x] = col;
}

Color Surface::GetPixel(int x, int y) const {
	assert(x >= 0);
	assert(x < width);
	assert(y >= 0);
	assert(y < height);

	return ptrPixels[y * width + x];
}

int Surface::GetWidth() const {
	return width;
}

int Surface::GetHeight() const {
	return height;
}
