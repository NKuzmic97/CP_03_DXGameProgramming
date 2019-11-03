/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"
#include <iostream>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go(){
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel() {
	InhibitMovement();

	cs_mobile.x += vx;
	cs_mobile.y += vy;

	CheckScreenBoundaries(cs_mobile);

	if (Collision(cs_mobile,cs_fixed) || Collision(cs_mobile,cs0) || Collision(cs_mobile,cs1))
		cs_mobile.c = Color(255, 0, 0);
	else
		cs_mobile.c = Color(255, 255, 255);
}

void Game::CheckScreenBoundaries(Crosshair & cs) {
	if (cs.x + 5 >= gfx.ScreenWidth) {
		cs.x = gfx.ScreenWidth - 5 - 1;
		DisableXVelocity();
	}
	if (cs.x - 5 < 0) {
		cs.x = 5;
		DisableXVelocity();
	}

	if (cs.y + 5 >= gfx.ScreenHeight) {
		cs.y = gfx.ScreenHeight - 5 - 1;
		DisableYVelocity();
	}

	if (cs.y - 5 < 0) {
		cs.y = 5;
		DisableYVelocity();
	}
}

void Game::InhibitMovement() {
	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		if (inhibitLeft) {}
		else {
			vx = vx - 1;
			inhibitLeft = true;
		}
	}
	else
		inhibitLeft = false;

	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		if (inhibitRight) {}
		else {
			vx = vx + 1;
			inhibitRight = true;
		}
	}
	else
		inhibitRight = false;

	if (wnd.kbd.KeyIsPressed(VK_UP)) {
		if (inhibitUp) {}
		else {
			vy = vy - 1;
			inhibitUp = true;
		}
	}
	else
		inhibitUp = false;

	if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
		if (inhibitDown) {}
		else {
			vy = vy + 1;
			inhibitDown = true;
		}
	}
	else
		inhibitDown = false;
}

void Game::BoxCrosshair(Crosshair& cs) {
	if(cs.alive){
	gfx.PutPixel(cs.x - 5, cs.y - 5, cs.c);
	gfx.PutPixel(cs.x - 4, cs.y - 5, cs.c);
	gfx.PutPixel(cs.x - 3, cs.y - 5, cs.c);
	gfx.PutPixel(cs.x - 5, cs.y - 4, cs.c);
	gfx.PutPixel(cs.x - 5, cs.y - 3, cs.c);

	gfx.PutPixel(cs.x + 5, cs.y - 5, cs.c);
	gfx.PutPixel(cs.x + 5, cs.y - 4, cs.c);
	gfx.PutPixel(cs.x + 5, cs.y - 3, cs.c);
	gfx.PutPixel(cs.x + 4, cs.y - 5, cs.c);
	gfx.PutPixel(cs.x + 3, cs.y - 5, cs.c);

	gfx.PutPixel(cs.x - 5, cs.y + 4, cs.c);
	gfx.PutPixel(cs.x - 5, cs.y + 5, cs.c);
	gfx.PutPixel(cs.x - 5, cs.y + 3, cs.c);
	gfx.PutPixel(cs.x - 4, cs.y + 5, cs.c);
	gfx.PutPixel(cs.x - 3, cs.y + 5, cs.c);

	gfx.PutPixel(cs.x + 5, cs.y + 4, cs.c);
	gfx.PutPixel(cs.x + 5, cs.y + 5, cs.c);
	gfx.PutPixel(cs.x + 4, cs.y + 5, cs.c);
	gfx.PutPixel(cs.x + 5, cs.y + 3, cs.c);
	gfx.PutPixel(cs.x + 3, cs.y + 5, cs.c);
}}

void Game::CS_Crosshair(int x, int y, Color &c) {
	gfx.PutPixel(x - 5, y, c);
	gfx.PutPixel(x - 4, y, c);
	gfx.PutPixel(x - 3, y, c);

	gfx.PutPixel(x + 3, y, c);
	gfx.PutPixel(x + 4, y, c);
	gfx.PutPixel(x + 5, y, c);

	gfx.PutPixel(x, y - 5, c);
	gfx.PutPixel(x, y - 4, c);
	gfx.PutPixel(x, y - 3, c);

	gfx.PutPixel(x, y + 3, c);
	gfx.PutPixel(x, y + 4, c);
	gfx.PutPixel(x, y + 5, c);
}

bool Game::Collision(Crosshair & player,Crosshair & other) {
	bool collision = abs(player.x - other.x) <= 10 && abs(player.y - other.y) <= 10;
	if (collision) other.alive = false;
	return collision;
}

void Game::ComposeFrame(){
	BoxCrosshair(cs_mobile);
	BoxCrosshair(cs_fixed);
	BoxCrosshair(cs0);
	BoxCrosshair(cs1);
}
