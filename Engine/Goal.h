#pragma once
#include "Graphics.h"
#include "Dude.h"

class Goal {
public:
	Goal(int x, int y) :
		x(x), y(y) {
	}
	void Draw(Graphics& gfx) const {
		gfx.DrawRect(c, x, y, dimension,dimension);
	}
	bool TestCollision(const class Dude& dude) const {
		const int duderight = dude.GetPosition().x + dude.GetWidth();
		const int dudebottom = dude.GetPosition().y + dude.GetHeight();
		const int right = x + dimension;
		const int bottom = y + dimension;

		return (duderight >= x &&
			dude.GetPosition().x <= right &&
			dudebottom >= y &&
			dude.GetPosition().y <= bottom);
	}
	void Respawn(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void UpdateColor() {
		if (colorIncreasing) {
			if (c.GetR() >= 253)
				colorIncreasing = false;
			else 
				c = Color(c.GetR() + 2, c.GetG() + 4, c.GetB() + 4);
		}
		else {
			if (c.GetR() <= 127)
				colorIncreasing = true;
			else
				c = Color(c.GetR() - 2, c.GetG() - 4, c.GetB() - 4);
		}
		
	}
private:
	static constexpr int dimension = 20;
	Color c = { 127,0,0 };
	bool colorIncreasing = true;
	int x, y;
};