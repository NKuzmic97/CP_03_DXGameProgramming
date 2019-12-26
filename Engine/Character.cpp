#include "Character.h"
#include "Graphics.h"

Character::Character(const Vec2& pos):
sprite("link90x90.bmp"),
pos(pos)

{
	for(int i=0;i<(int)Sequence::StandingLeft;i++) {
		animations.emplace_back(Animation(90, 90 * i, 90, 90, 4, sprite, 0.16f));
	}
	
	for (int i = int(Sequence::StandingLeft); i < (int)Sequence::Count; i++) {
		animations.emplace_back(Animation(0, 90 * (i - (int)Sequence::StandingLeft), 90, 90, 1, sprite, 0.16f));
	}
}

void Character::Draw(Graphics& gfx) const {
	if(effectActive) {
		animations[(int)curSeq].DrawColor((Vei2)pos, gfx, Colors::Red);

	}
	else {
		animations[(int)curSeq].Draw((Vei2)pos, gfx);
	}
}

void Character::SetDirection(const Vec2& dir) {
	
	if(dir.x > 0.0f) {
		curSeq = Sequence::WalkingRight;
	}
	else if (dir.x < 0.0f) {
		curSeq = Sequence::WalkingLeft;
	}
	else if (dir.y > 0.0f) {
		curSeq = Sequence::WalkingDown;
	}
	else if (dir.y < 0.0f) {
		curSeq = Sequence::WalkingUp;
	}

	else {
		if(vel.x > 0.0f) {
			curSeq = Sequence::StandingRight;
		}
		else if(vel.x < 0.0f) {
			curSeq = Sequence::StandingLeft;
		}
		else if(vel.y > 0.0f) {
			curSeq = Sequence::StandingDown;
		}
		else if(vel.y < 0.0f) {
			curSeq = Sequence::StandingUp;
		}
	}

	vel = dir * speed;
}

void Character::Update(float dt) {
	pos += vel * dt;
	animations[(int)curSeq].Update(dt);
	if(effectActive) {
		effectTime += dt;
		if(effectTime >= effectDuration) {
			effectActive = false;
		}
	}
}

void Character::ActivateEffect() {
	effectActive = true;
	effectTime = 0.0f;
}
