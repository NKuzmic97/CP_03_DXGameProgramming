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

int Ball::DoWallCollision(const RectF & walls) {
	const RectF rect = GetRect();

	if (rect.left < walls.left) {
		pos.x += walls.left - rect.left;
		ReboundX();
		return 1;
	}
	else if (rect.right > walls.right) {
		pos.x -= rect.right - walls.right;

		ReboundX();
		return 1;

	}

	if (rect.top < walls.top) {
		pos.y += walls.top - rect.top;
		ReboundY();
		return 1;

	}
	else if (rect.bottom > walls.bottom) {
		pos.y -= rect.bottom - walls.bottom;
		ReboundY();
		return 2;
	}

	return 0;
}

void Ball::ReboundX() {
	vel.x = -vel.x;
}

void Ball::ReboundY() {
	vel.y = -vel.y;
}

RectF Ball::GetRect() const {
	return RectF::FromCenter(pos, radius, radius);
}

Vec2 Ball::GetVelocity() const {
	return vel;
}

Vec2 Ball::GetPosition() const {
	return pos;
}
