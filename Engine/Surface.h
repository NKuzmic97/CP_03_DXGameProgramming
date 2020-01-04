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
	Surface( const Surface& );
	Surface(Surface && donor);
	Surface& operator=(Surface&& donor);
	Surface& operator=(const Surface&);
	~Surface();
	
	void PutPixel( int x,int y,Color c );
	Color GetPixel( int x,int y ) const;
	int GetWidth() const;
	int GetHeight() const;
	RectI GetRect() const;
	const Color* Data() const;
private:
	Color* pPixels = nullptr;
	int width = 0;
	int height = 0;
};
