#pragma once
#include "Vec2.h"
#include "Graphics.h"

class Ball {
public:
	Ball(const Vec2& pos_, const Vec2& vel_);
	void Draw (Graphics& gfx) const;
private:
	static constexpr float radius = 7.0f;
	Vec2 pos;
	Vec2 vel;
};