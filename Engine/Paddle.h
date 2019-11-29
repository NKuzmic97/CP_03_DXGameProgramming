#pragma once
#include "Ball.h"
#include "Vec2.h"
#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"
#include "Keyboard.h"

class Paddle {
public:
	Paddle(const Vec2& pos_, float halfWidth_, float halfHeight_);
	void Draw(Graphics& gfx) const;
	bool DoBallCollision(Ball& ball);
	void DoWallCollision(const RectF& walls);
	void Update(const Keyboard& kbd, float dt);
	RectF GetRect() const;
	void ResetCooldown();
private:
	static constexpr float swingWidth = 20.0f;
	static constexpr float sexitXFactor = 0.045f;
	static constexpr float sfixedZoneHalfWidth = 15.0f;
	static constexpr Color wingColor = Colors::Red;
	static constexpr Color color = Colors::White;
	static constexpr float speed = 300.0f;
	// control the paddle rebound behaviour here
	static constexpr float smaximumExitRatio = 2.6f;
	static constexpr float sfixedZoneWidthRatio = 0.2f;
	// ------------------------------------------
	//these are derived from above controls
	float exitXFactor;
	float fixedZoneHalfWidth;
	float fixedZoneExitX;

	float halfWidth;
	float halfHeight;

	Vec2 pos;
	bool isCooldown = false;
};