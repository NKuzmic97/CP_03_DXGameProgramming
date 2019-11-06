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

void Game::ComposeFrame(){
	static int x = 100;
	static int y = 100;
	static int width = 100;
	static int height = 100;

	if (wnd.kbd.KeyIsPressed(VK_UP)) y--;
	else if (wnd.kbd.KeyIsPressed(VK_DOWN)) y++;
	if (wnd.kbd.KeyIsPressed(VK_LEFT)) x--;
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT)) x++;

	if (wnd.kbd.KeyIsPressed('A')) width--;
	else if (wnd.kbd.KeyIsPressed('D')) width++;
	if (wnd.kbd.KeyIsPressed('W')) height--;
	else if (wnd.kbd.KeyIsPressed('S')) height++;
	

	for (int i = x; i < x+width; i++) {
		for (int j = y; j < y+height; j++) {
			gfx.PutPixel(i, j, 255, 255, 255);
		}
	}
}
