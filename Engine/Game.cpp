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
#include <random>

Game::Game( MainWindow& wnd )
	:
	wnd(wnd),gfx(wnd),
	d0(wnd), renderer(gfx){}

void Game::Go(){
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}
void Game::UpdateModel(){
	if(IsStarted){
	d0.Update();
	p0.Update();
	p1.Update();
	p2.Update();

	if (IsColliding(d0,p0)) p0.IsEaten = true;
	if (IsColliding(d0,p1)) p1.IsEaten = true;
	if (IsColliding(d0,p2)) p2.IsEaten = true;
}

	else if (wnd.kbd.KeyIsPressed(VK_RETURN))
			IsStarted = true;
}
bool Game::IsColliding(const Dude& dude,const Poo& poo) {
	int left0 = dude.x;
	int right0 = dude.x + dude.width;
	int top0 = dude.y;
	int bottom0 = dude.y + dude.height;

	int left1 = poo.x;
	int right1 = poo.x + poo.width;
	int top1 = poo.y;
	int bottom1 = poo.y + poo.height;

	return right0 >= left1 &&
		bottom0 >= top1 &&
		left0 <= right1 &&
		top0 <= bottom1;
}
void Game::ComposeFrame(){
	if (!IsStarted) {
		renderer.Draw(DrawID::TITLE_SCREEN,325,211);
		return;
	}

	renderer.Draw(DrawID::DUDE_ID,0,0,&d0);

	if (p0.IsEaten && p1.IsEaten && p2.IsEaten) renderer.Draw(DrawID::GAME_OVER, 358, 268, 0);
	if (!p0.IsEaten) renderer.Draw(DrawID::POO_ID, 0, 0, &p0);
	if (!p1.IsEaten) renderer.Draw(DrawID::POO_ID, 0, 0, &p1);
	if (!p2.IsEaten) renderer.Draw(DrawID::POO_ID, 0, 0, &p2);
}
