#pragma once
#include "Graphics.h"
#include "Location.h"

class Board {
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);
	static int GetGridWidth();
	static int GetGridHeight();
private:
	static constexpr int dimension = 20;
	static constexpr int width = 10, height = 10;
	Graphics& gfx;
};