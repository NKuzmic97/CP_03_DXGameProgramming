#include "Board.h"
#include <assert.h>

Board::Board(Graphics& gfx):
gfx(gfx){
}

void Board::DrawCell(const Location &loc, Color c) {
	assert(loc.x >= 0 + fromLeft);
	assert(loc.x < width + fromLeft);
	assert(loc.y >= 0 + fromTop);
	assert(loc.y < height + fromTop);

	gfx.DrawRectDim(loc.x * dimension, loc.y*dimension, dimension - padding, dimension - padding, c);
	DrawBorder();
}

void Board::DrawBorder() {
	gfx.DrawRectDim(0 + (fromLeft * dimension), 0 + (fromTop * dimension), dimension * width + 1, dimension, Colors::Magenta); // Top
	gfx.DrawRectDim(0 + (fromLeft * dimension), (height + fromTop) * dimension , dimension * (width + 1), dimension, Colors::Magenta); // Bottom

	gfx.DrawRectDim(0 + (fromLeft * dimension), 0 + (fromTop * dimension), dimension, dimension * height, Colors::Magenta); // Left
	gfx.DrawRectDim((width + fromLeft)*dimension, 0 + (dimension * fromTop), dimension, dimension * height, Colors::Magenta); // Right
}

int Board::GetGridWidth() {
	return width;
}

int Board::GetGridHeight() {
	return height;
}

bool Board::IsInsideBoard(const Location & loc) const {
	return loc.x >= 0 + fromLeft + 1 && loc.x < width + fromLeft &&
		loc.y >= 0 + fromTop + 1 && loc.y < height + fromTop;
}

void Board::MoveBorderUp() {
	if (fromTop > 0) fromTop--;
}

void Board::MoveBorderDown() {
	const int maxSpacingHeight = (Graphics::ScreenHeight - (dimension*height)) / dimension - 1;

	if(fromTop < maxSpacingHeight) 
		fromTop++;
}

void Board::MoveBorderLeft() {
	if (fromLeft > 0) fromLeft--;
}

void Board::MoveBorderRight() {
	const int maxSpacingWidth = (Graphics::ScreenWidth - (dimension*width)) / dimension - 1;

	if(fromLeft < maxSpacingWidth) 
		fromLeft++;
}

int Board::GetOffsetLeft() const {
	return fromLeft;
}

int Board::GetOffsetTop() const {
	return fromTop;
}
