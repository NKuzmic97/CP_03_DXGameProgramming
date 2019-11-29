#include "Paddle.h"

Paddle::Paddle(
	const Vec2 & pos_, 
	float halfWidth_, 
	float halfHeight_)
:
	pos(pos_),
	halfWidth(halfWidth_),
	halfHeight(halfHeight_),
	exitXFactor(smaximumExitRatio/halfWidth),
	fixedZoneHalfWidth(halfWidth * sfixedZoneWidthRatio),
	fixedZoneExitX(fixedZoneHalfWidth * exitXFactor)
{
	//
}

void Paddle::Draw(Graphics & gfx) const {
	RectF rect = GetRect();
	gfx.DrawRect(rect, wingColor);
	rect.left += swingWidth;
	rect.right -= swingWidth;
	gfx.DrawRect(rect, color);
}

bool Paddle::DoBallCollision(Ball & ball) {
	if (!isCooldown) {
		const RectF rect = GetRect();

		if (rect.IsOverlapingWith(ball.GetRect())) {
			const Vec2 ballPos = ball.GetPosition();

			if (std::signbit(ball.GetVelocity().x) == std::signbit((ballPos - pos).x) ||
				ballPos.x >= rect.left && ballPos.x <= rect.right) 
			{
				Vec2 dir;
				const float xDiff = ballPos.x - pos.x;
				const float fixedXComponent = fixedZoneHalfWidth * exitXFactor;

				if (std::abs(xDiff) < fixedZoneHalfWidth) {
					if (xDiff < 0.0f) {
						dir = Vec2(-fixedZoneExitX, -1.0f);
					}
					else {
						dir = Vec2(fixedZoneExitX, -1.0f);
					}
				}
				else {
					dir = Vec2(xDiff * exitXFactor, -1.0f);
				}
				ball.SetDirection(dir);
			}
			else {
				ball.ReboundX();
			}
			isCooldown = true;
			return true;
		}
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

void Paddle::ResetCooldown() {
	isCooldown = false;
}

void Paddle::Update(const Keyboard& kbd, float dt) {
	if (kbd.KeyIsPressed(VK_LEFT)) {
		pos.x -= speed * dt;
	}
	else if (kbd.KeyIsPressed(VK_RIGHT)) {
		pos.x += speed * dt;
	}
}
