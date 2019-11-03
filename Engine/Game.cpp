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
	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		if(inhibitLeft){}
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

	x += vx;
	y += vy;

	if (x + 5 >= gfx.ScreenWidth) {
		x = gfx.ScreenWidth - 5 - 1;
		DisableXVelocity();
	}
	if (x - 5 < 0){
		x = 5;
		DisableXVelocity();
	}

	if (y + 5 >= gfx.ScreenHeight){
		y = gfx.ScreenHeight - 5 - 1;
		DisableYVelocity();
	}

	if (y - 5 < 0){
		y = 5;
		DisableYVelocity();
	}

	if (abs(x - x1) <= 10 && abs(y - y1) <= 10)
		c = Color(255, 0, 0);
	else
		c = Color(255, 255, 255);
}

void Game::DisableYVelocity() {
	vy = 0;
}

void Game::DisableXVelocity() {
	vx = 0;
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
	BoxCrosshair(x, y, c);
	BoxCrosshair(x1, y1, c1);
}
