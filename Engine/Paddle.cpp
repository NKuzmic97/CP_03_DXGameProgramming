#include "Paddle.h"

Paddle::Paddle(
	const Vec2 & pos_, 
	float halfWidth_, 
	float halfHeight_)
:
	pos(pos_),
	halfWidth(halfWidth_),
	halfHeight(halfHeight_)
{
	//
}

void Paddle::Draw(Graphics & gfx) const {
	RectF rect = GetRect();
	gfx.DrawRect(rect, wingColor);
	rect.left += wingWidth;
	rect.right -= wingWidth;
	gfx.DrawRect(rect, color);
}

bool Paddle::DoBallCollision(Ball & ball) const {
	if ( ball.GetVelocity().y > 0 && 
		 GetRect().IsOverlapingWith(ball.GetRect()) ) {
		ball.ReboundY();
		return true;
	}
	return false;
}

void Paddle::DoWallCollision(const RectF & walls) {
	const RectF rect = GetRect();
	if (rect.left < walls.left) {
		pos.x += walls.left - rect.left;
	}
	else if (rect.right > walls.right) {
		pos.x -= rect.right - walls.right;
	}
}

RectF Paddle::GetRect() const {
	return RectF::FromCenter(pos,halfWidth,halfHeight);
}

void Paddle::Update(const Keyboard& kbd, float dt) {
	if (kbd.KeyIsPressed(VK_LEFT)) {
		pos.x -= speed * dt;
	}
	else if (kbd.KeyIsPressed(VK_RIGHT)) {
		pos.x += speed * dt;
	}
}
