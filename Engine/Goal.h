#pragma once

#include "Graphics.h"
#include "Dude.h"
#include "Vec2.h"

class Goal
{
public:
	Goal(const Vec2& pos_)
		:
		pos(pos_)
	{}

	void Draw( Graphics& gfx ) const
	{
		gfx.DrawRectDim( (int)pos.x,(int)pos.y,(int)dimension,(int)dimension,c );
	}

	bool TestCollision( const Dude& dude ) const
	{
		const float duderight = dude.GetPosition().x + dude.GetWidth();
		const float dudebottom = dude.GetPosition().y + dude.GetHeight();
		const float pooright = pos.x + dimension;
		const float poobottom = pos.y + dimension;

		return
			duderight >= pos.x &&
			dude.GetPosition().x <= pooright &&
			dudebottom >= pos.y &&
			dude.GetPosition().y <= poobottom;
	}
	void Respawn(const Vec2& other)
	{
		pos = other;
	}

	void UpdateColor()
	{
		if( colorIncreasing )
		{
			if( c.GetR() >= 253 )
			{
				colorIncreasing = false;
			}
			else
			{
				c = Color( c.GetR() + 2,c.GetG() + 4,c.GetB() + 4 );
			}
		}
		else
		{
			if( c.GetR() <= 127 )
			{
				colorIncreasing = true;
			}
			else
			{
				c = Color( c.GetR() - 2,c.GetG() - 4,c.GetB() - 4 );
			}
		}
	}
private:
	static constexpr float dimension = 20;
	Color c = { 127,0,0 };
	bool colorIncreasing = true;
	Vec2 pos;
};