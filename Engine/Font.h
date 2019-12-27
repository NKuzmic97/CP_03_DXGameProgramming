#pragma once
#include "Surface.h"
#include "Vec2.h"

class Font {
public:
	Font(const std::string& filename, Color chroma = Colors::White);
	void DrawText(const std::string& text, const Vei2& pos,Color color,class Graphics& gfx) const;
private:
	RectI MapGlyphRect(char c) const;
private:
	// holds the font sheet bitmap data
	Surface surface;
	// this gives the dimensions of a glyph in the font sheet
	int glyphWidth, glyphHeight;
	// numbers of rows / columns in the font sheet (fixed)
	static constexpr int numColumns = 32;
	static constexpr int numRows = 3;
	// font sheet chroma color
	Color chroma;
	// start and end drawable char codes
	static constexpr char firstChar = ' ';
	static constexpr char endChar = '~';
};

