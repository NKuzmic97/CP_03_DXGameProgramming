#include "Brick.h"

Brick::Brick(
	const RectF & rec_, 
	Color color_ )
	:
	rect(rec_),
	color(color_)
{
	//
}

void Brick::Draw(Graphics & gfx) const {
	if(!destroyed)
		gfx.DrawRect(rect.GetExpanded(-padding) , color);
}

bool Brick::DoBallCollision(Ball & ball) {
	if (!destroyed && rect.IsOverlapingWith(ball.GetRect())) {
		ball.ReboundY();
		destroyed = true;
		return true;
	}
	return false;
}
