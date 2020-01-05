#pragma once

#include "Colors.h"
#include <string>
#include "Rect.h"
#include <vector>

class Surface
{
public:
	Surface() = default;
	Surface( const std::string& filename );
	Surface( int width,int height );
	Surface(Surface&& donor);
	Surface(const Surface&) = default;
	Surface& operator=(const Surface&) = default;
	Surface& operator=(Surface&& rhs);
	~Surface() = default;

	void PutPixel( int x,int y,Color c );
	Color GetPixel( int x,int y ) const;
	int GetWidth() const;
	int GetHeight() const;
	RectI GetRect() const;
	const Color* Data() const;
	void Fill(Color color);
private:
	std::vector<Color> pixels;
	int width = 0;
	int height = 0;
};
