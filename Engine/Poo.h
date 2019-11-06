#pragma once
#include "Graphics.h"

class Poo {
private:
	Graphics& gfx;
private:
	void MovementRandomize();
	void PositionRandomize();
public:
	Poo(Graphics& gfx);
	void Update();
	void Draw();
public:
	static constexpr int width = 24, height = 24;
	int x, y;
	int vx, vy;
	bool IsEaten = false;
};