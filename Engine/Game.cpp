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

void NoSignal(Graphics& gfx) {
	int x, y;
	for (x = 0; x < gfx.ScreenWidth; x++) {
		for (y = 0; y < gfx.ScreenHeight; y++) {
			gfx.PutPixel(x, y, rand(), rand(), rand());
		}
	}
}

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
}

void Game::Crosshair() {
	static int x = 400;
	static int y = 300;
	static Color c = Color(255, 255, 255);
	static bool cs_Crosshair = true;

	if ((GetAsyncKeyState(VK_LEFT) & 1) && x!= 300)
		x -= 100;
	else if ((GetAsyncKeyState(VK_RIGHT) & 1) && x!= 500)
		x += 100;

	if ((GetAsyncKeyState(VK_UP) & 1) && y!= 200)
		y -= 100;
	else if ((GetAsyncKeyState(VK_DOWN) & 1) && y!= 400)
		y += 100;

	if (GetAsyncKeyState(VK_SHIFT) & 1){
		static bool red = true;
		if (red) {
			c = Color(255, 0, 0); 
		}
		else 
			c = Color(255, 255, 255);
		red = !red;
	}

	if(GetAsyncKeyState(VK_SPACE) & 1){
		cs_Crosshair = !cs_Crosshair;
	}
	if(cs_Crosshair){
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
	else {
		gfx.PutPixel(x - 5, y - 4, c);
		gfx.PutPixel(x - 5, y - 5, c);
		gfx.PutPixel(x - 4, y - 5, c);
		gfx.PutPixel(x - 5, y - 3, c);
		gfx.PutPixel(x - 3, y - 5, c);

		gfx.PutPixel(x + 5, y - 4, c);
		gfx.PutPixel(x + 5, y - 5, c);
		gfx.PutPixel(x + 4, y - 5, c);
		gfx.PutPixel(x + 5, y - 3, c);
		gfx.PutPixel(x + 3, y - 5, c);

		gfx.PutPixel(x - 5, y + 4, c);
		gfx.PutPixel(x - 5, y + 5, c);
		gfx.PutPixel(x - 4, y + 5, c);
		gfx.PutPixel(x - 5, y + 3, c);
		gfx.PutPixel(x - 3, y + 5, c);

		gfx.PutPixel(x + 5, y + 4, c);
		gfx.PutPixel(x + 5, y + 5, c);
		gfx.PutPixel(x + 4, y + 5, c);
		gfx.PutPixel(x + 5, y + 3, c);
		gfx.PutPixel(x + 3, y + 5, c);
	}
}

void Game::ComposeFrame(){
	Crosshair();
}
