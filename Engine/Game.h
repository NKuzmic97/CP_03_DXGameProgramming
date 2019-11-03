/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

class Game {
	struct Crosshair {
		int x = 400, y = 300;
		Color c = Color(255,255,255);
		bool alive = true;
		Crosshair(int x,int y,Color c):x(x),y(y),c(c){}
		Crosshair() = default;
	};

public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	void CheckScreenBoundaries(Crosshair& cs);
	void InhibitMovement();
	inline void DisableYVelocity() { vy = 0; };
	inline void DisableXVelocity() { vx = 0; };
	void BoxCrosshair(Crosshair& cs);
	void CS_Crosshair(int x, int y, Color &c);
	bool Collision(Crosshair& player, Crosshair& other);
private:
	MainWindow& wnd;
	Graphics gfx;

	Crosshair cs_mobile;
	Crosshair cs_fixed = Crosshair(150, 250, Color(0, 255, 0));
	Crosshair cs0 = Crosshair(50, 400, Color(255, 255, 0));
	Crosshair cs1 = Crosshair(500, 300, Color(0, 255, 255));

	int vx = 0;
	int vy = 1;

	bool inhibitUp = false; 
	bool inhibitDown = false;
	bool inhibitLeft = false;
	bool inhibitRight = false;
};