#pragma once
#include "Graphics.h"
#include "Location.h"

class Board {
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);
	void DrawBorder();
	static int GetGridWidth();
	static int GetGridHeight();
	bool IsInsideBoard(const Location& loc) const;

	void MoveBorderUp();
	void MoveBorderDown();
	void MoveBorderLeft();
	void MoveBorderRight();

	int GetOffsetLeft() const;
	int GetOffsetTop() const;

private:
	static constexpr int dimension = 20;
	static constexpr int width = 25, height = 25;
	static constexpr int padding = 1;
	int fromLeft = 0, fromTop = 0;
	Graphics& gfx;
};