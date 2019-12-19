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

	assert(bmpInfoHeader.biBitCount == 24 || bmpInfoHeader.biBitCount == 32);
	assert(bmpInfoHeader.biCompression == BI_RGB);

	width = bmpInfoHeader.biWidth;
	height = bmpInfoHeader.biHeight;

	bool reverse = bmpInfoHeader.biHeight < 0;

	height = abs(height);

	ptrPixels = new Color[width*height];

	file.seekg(bmpFileHeader.bfOffBits);

	bool bmp24 = bmpInfoHeader.biBitCount == 24 ? true : false;
	
		const int padding = bmp24 ? (4 - (width * 3) % 4) % 4 : 0;
	
			for (int y = (reverse ? 0 : height - 1); reverse ? y < height : y >= 0; reverse ? y++ : y--) {
				for (int x = 0; x < width; x++) {
					if (bmp24) {
						PutPixel(x, y, Color(file.get(), file.get(), file.get()));
					}
					else {
						PutPixel(x, y, Color(file.get(),file.get(), file.get(), file.get()));
					}
				}
				file.seekg(padding, std::ios::cur);
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
