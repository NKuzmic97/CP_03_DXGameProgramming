#pragma once
#include "Vec2.h"

class RectF {
public:
	RectF() = default;
	RectF(float left_, float right_, float top_, float bottom_);
	RectF(const Vec2& topLeft, const Vec2& bottomRight);
	RectF(const Vec2& topLeft, float width, float height);
	bool IsOverlapingWith(const RectF& other) const;
public:
	float left, right;
	float top, bottom;
};