#include "RectF.h"

RectF::RectF (
	float left_, 
	float right_, 
	float top_, 
	float bottom_)
:
	left(left_),
	right(right_),
	top(top_),
	bottom(bottom_)
{
	//
}

RectF::RectF(
	const Vec2 & topLeft, 
	const Vec2 & bottomRight) 
	:
	RectF(topLeft.x,bottomRight.x,topLeft.y,bottomRight.y)
{
	//
}

RectF::RectF(
	const Vec2 & topLeft, 
	float width, 
	float height)
	:
	RectF(topLeft,topLeft+Vec2(width,height))
{
	//
}

bool RectF::IsOverlapingWith(const RectF & other) const {
	return  right > other.left &&
			left < other.right &&
			bottom > other.top &&
			top < other.bottom;
}
