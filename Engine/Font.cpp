#include "Font.h"
#include <cassert>
#include "Graphics.h"

Font::Font(const std::string& filename, Color chroma)
	:
	surface(filename),
	// calculate glyph dimensions from bitmap dimensions
	glyphWidth(surface.GetWidth()/numColumns),
	glyphHeight(surface.GetHeight()/numRows),
	chroma(chroma)
{
	// verify that bitmap had valid dimensions
	assert(glyphWidth * numColumns == surface.GetWidth());
	assert(glyphHeight * numRows == surface.GetHeight());
}

void Font::DrawText(const std::string& text, const Vei2& pos,Color color, Graphics& gfx) const {
	// curPos is the pos that we are drawing to on the screen
	auto curPos = pos;
	for(auto c : text) {
		// on a newline character, reset position x and advance y by 1
		if( c== '\n') {
			// carriage return
			curPos.x = pos.x;
			// line feed
			curPos.y += glyphHeight;
			// we don't want to advance to character drawing
			continue;;
		}
		
		// only draw characters that are on the font sheet
		// firstChar + 1 because might as well skip ' '
		else if( c >= firstChar +1 && c <= endChar) {
			gfx.DrawSpriteSubstitute(curPos.x, curPos.y,color, MapGlyphRect(c),Graphics::GetScreenRect(), surface,chroma);
		}
		// advance screen pos for next character
		curPos.x += glyphWidth;
	}
}

RectI Font::MapGlyphRect(char c) const {
	assert(c >= firstChar && c <= endChar);
	// font sheet glyphs start at ' ', calculate index into sheet
	const int glyphIndex = c - ' ';
	// map 1d glyphIndex to 2D coordinates
	const int xGlyph = glyphIndex % numColumns;
	const int yGlyh = glyphIndex / numColumns;
	// convert the sheet grid coords to pixel coords in sheet
	return RectI(
		{ xGlyph * glyphWidth,yGlyh * glyphHeight }, 
		glyphWidth, 
		glyphHeight);
}
