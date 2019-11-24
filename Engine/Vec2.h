#pragma once

class Vec2 {
public:
	Vec2(float x_, float y_);
	Vec2() = default;
	Vec2 operator+(const Vec2& rhs) const; // lhs + rhs
	Vec2& operator+=(const Vec2& rhs);
	Vec2 operator*(const float scalar) const;
public:
	float x, y;
};