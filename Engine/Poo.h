#pragma once

#include "Graphics.h"
#include "Dude.h"

class Poo
{
public:
	void Init(const Vec2& pos_,const Vec2& vel_);
	void Update(float dt);
	bool TestCollision( const Dude& dude ) const;
	void Draw( Graphics& gfx ) const;
private:
	Vec2 pos;
	Vec2 vel;
	static constexpr float width = 24.0f;
	static constexpr float height = 24.0f;
	bool initialized = false;
};