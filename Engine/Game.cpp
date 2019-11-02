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

void Game::NoSignal() {
	for (x = 0; x < gfx.ScreenWidth; x++) {
		for (y = 0; y < gfx.ScreenHeight; y++) {
			gfx.PutPixel(x, y, rand(), rand(), rand());
		}
	}
	x = 400;
	y = 300;
}

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	x(400),
	y(300),
	c(255, 255, 255),
	ShapeIsChanged(true),
	velocity(0),
	gravity(1)
{
}

void Game::Go(){
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel() {

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
		velocity = -1;
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		velocity = 1;

	if (wnd.kbd.KeyIsPressed(VK_UP))
		gravity = -1;
	else 
		gravity = 1;

	if (GetAsyncKeyState(VK_SHIFT) & 1) {
		static bool red = true;
		if (red) {
			c = Color(255, 0, 0);
		}
		else
			c = Color(255, 255, 255);
		red = !red;
	}

	if (GetAsyncKeyState(VK_SPACE) & 1)
		ShapeIsChanged = !ShapeIsChanged;
	
	x += velocity;
	y += gravity;
}

void Game::BoxCrosshair(int x, int y, Color &c) {
	gfx.PutPixel(x - 5, y - 5, c);
	gfx.PutPixel(x - 4, y - 5, c);
	gfx.PutPixel(x - 3, y - 5, c);
	gfx.PutPixel(x - 5, y - 4, c);
	gfx.PutPixel(x - 5, y - 3, c);

	gfx.PutPixel(x + 5, y - 5, c);
	gfx.PutPixel(x + 5, y - 4, c);
	gfx.PutPixel(x + 5, y - 3, c);
	gfx.PutPixel(x + 4, y - 5, c);
	gfx.PutPixel(x + 3, y - 5, c);

	gfx.PutPixel(x - 5, y + 4, c);
	gfx.PutPixel(x - 5, y + 5, c);
	gfx.PutPixel(x - 5, y + 3, c);
	gfx.PutPixel(x - 4, y + 5, c);
	gfx.PutPixel(x - 3, y + 5, c);

	gfx.PutPixel(x + 5, y + 4, c);
	gfx.PutPixel(x + 5, y + 5, c);
	gfx.PutPixel(x + 4, y + 5, c);
	gfx.PutPixel(x + 5, y + 3, c);
	gfx.PutPixel(x + 3, y + 5, c);
}

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

void Game::ComposeFrame(){
	if (ShapeIsChanged)
		CS_Crosshair(x, y, c);
	else
		BoxCrosshair(x, y, c);
}
