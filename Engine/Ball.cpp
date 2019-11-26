#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(
	const Vec2 & pos_, 
	const Vec2 & vel_) 
	:
	pos(pos_),
	vel(vel_)
{
	//
}

void Ball::Draw(Graphics & gfx) const {
	SpriteCodex::DrawBall(pos, gfx);
}

void Ball::Update(float dt) {
	pos += vel * dt;
}
