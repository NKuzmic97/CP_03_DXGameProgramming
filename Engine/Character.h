#pragma once
#include "Vec2.h"
#include <vector>
#include "Animation.h"

class Character {
private:
	enum class Sequence {
		WalkingLeft,
		WalkingRight,
		WalkingUp,
		WalkingDown,
		StandingLeft,
		StandingRight,
		StandingUp,
		StandingDown,
		Count
	};
public:
	Character(const Vec2& pos);
	void Draw(class Graphics& gfx) const;
	void SetDirection(const Vec2& dir);
	void Update(float dt);
	void ActivateEffect();
private:
	Surface sprite;
	Vec2 pos;
	Vec2 vel = { 0.0f,0.0f };
	std::vector<Animation> animations;
	Sequence curSeq = Sequence::StandingDown;
	float speed = 80.0f;
	static constexpr float effectDuration = 0.045f;
	float effectTime = 0.0f;
	bool effectActive = false;
};

