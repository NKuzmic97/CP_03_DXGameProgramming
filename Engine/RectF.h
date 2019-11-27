#pragma once
#include "Vec2.h"

class RectF {
public:
	RectF() = default;
	RectF(float left_, float right_, float top_, float bottom_);
	RectF(const Vec2& topLeft, const Vec2& bottomRight);
	RectF(const Vec2& topLeft, float width, float height);
	bool IsOverlapingWith(const RectF& other) const;
	static RectF FromCenter(const Vec2& center, float halfWidth, float halfHeight);
public:
	float left, right;
	float top, bottom;
};