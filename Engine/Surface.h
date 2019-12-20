#pragma once
#include "Colors.h"
#include <string>
#include "RectI.h"

class Surface {
public:
	Surface(int width, int height);
	Surface(const std::string& filename);
	Surface(const Surface&);
	Surface& operator=(const Surface&);
	~Surface();

	void PutPixel(int x, int y, Color col);
	Color GetPixel(int x, int y) const;
	int GetWidth() const;
	int GetHeight() const;
	RectI GetRect() const;
private:
	Color* ptrPixels = nullptr;
	int width;
	int height;
};