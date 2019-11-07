#include "Dude.h"
#include "Graphics.h"
#include "Keyboard.h"

void Dude::Update(const Keyboard& kbd) {
	if (kbd.KeyIsPressed(VK_RIGHT))
	position.x += speed;
	if (kbd.KeyIsPressed(VK_LEFT))
		position.x -= speed;
	if (kbd.KeyIsPressed(VK_DOWN))
		position.y += speed;
	if (kbd.KeyIsPressed(VK_UP)) 
		position.y -= speed;
}



void Dude::ClampToScreen()
{
	const int right = position.x + width;
	if(position.x < 0 )
	{
		position.x = 0;
	}
	else if( right >= Graphics::ScreenWidth )
	{
		position.x = (Graphics::ScreenWidth - 1) - width;
	}

	const int bottom = position.y + height;
	if(position.y < 0 )
	{
		position.y = 0;
	}
	else if( bottom >= Graphics::ScreenHeight )
	{
		position.y = (Graphics::ScreenHeight - 1) - height;
	}
}

void Dude::Draw(Graphics & gfx) const {
		gfx.PutPixel(7 + position.x, 0 + position.y, 0, 0, 0);
		gfx.PutPixel(8 + position.x, 0 + position.y, 0, 0, 0);
		gfx.PutPixel(9 + position.x, 0 + position.y, 0, 0, 0);
		gfx.PutPixel(10 + position.x, 0 + position.y, 0, 0, 0);
		gfx.PutPixel(11 + position.x, 0 + position.y, 0, 0, 0);
		gfx.PutPixel(12 + position.x, 0 + position.y, 0, 0, 0);
		gfx.PutPixel(5 + position.x, 1 + position.y, 0, 0, 0);
		gfx.PutPixel(6 + position.x, 1 + position.y, 0, 0, 0);
		gfx.PutPixel(7 + position.x, 1 + position.y, 254, 221, 88);
		gfx.PutPixel(8 + position.x, 1 + position.y, 254, 221, 88);
		gfx.PutPixel(9 + position.x, 1 + position.y, 254, 221, 88);
		gfx.PutPixel(10 + position.x, 1 + position.y, 254, 221, 88);
		gfx.PutPixel(11 + position.x, 1 + position.y, 254, 221, 88);
		gfx.PutPixel(12 + position.x, 1 + position.y, 254, 221, 88);
		gfx.PutPixel(13 + position.x, 1 + position.y, 0, 0, 0);
		gfx.PutPixel(14 + position.x, 1 + position.y, 0, 0, 0);
		gfx.PutPixel(3 + position.x, 2 + position.y, 0, 0, 0);
		gfx.PutPixel(4 + position.x, 2 + position.y, 0, 0, 0);
		gfx.PutPixel(5 + position.x, 2 + position.y, 254, 221, 88);
		gfx.PutPixel(6 + position.x, 2 + position.y, 254, 221, 88);
		gfx.PutPixel(7 + position.x, 2 + position.y, 254, 221, 88);
		gfx.PutPixel(8 + position.x, 2 + position.y, 254, 221, 88);
		gfx.PutPixel(9 + position.x, 2 + position.y, 254, 221, 88);
		gfx.PutPixel(10 + position.x, 2 + position.y, 254, 221, 88);
		gfx.PutPixel(11 + position.x, 2 + position.y, 254, 221, 88);
		gfx.PutPixel(12 + position.x, 2 + position.y, 254, 221, 88);
		gfx.PutPixel(13 + position.x, 2 + position.y, 254, 221, 88);
		gfx.PutPixel(14 + position.x, 2 + position.y, 254, 221, 88);
		gfx.PutPixel(15 + position.x, 2 + position.y, 0, 0, 0);
		gfx.PutPixel(16 + position.x, 2 + position.y, 0, 0, 0);
		gfx.PutPixel(2 + position.x, 3 + position.y, 0, 0, 0);
		gfx.PutPixel(3 + position.x, 3 + position.y, 254, 221, 88);
		gfx.PutPixel(4 + position.x, 3 + position.y, 254, 221, 88);
		gfx.PutPixel(5 + position.x, 3 + position.y, 254, 221, 88);
		gfx.PutPixel(6 + position.x, 3 + position.y, 254, 221, 88);
		gfx.PutPixel(7 + position.x, 3 + position.y, 254, 221, 88);
		gfx.PutPixel(8 + position.x, 3 + position.y, 254, 221, 88);
		gfx.PutPixel(9 + position.x, 3 + position.y, 254, 221, 88);
		gfx.PutPixel(10 + position.x, 3 + position.y, 254, 221, 88);
		gfx.PutPixel(11 + position.x, 3 + position.y, 254, 221, 88);
		gfx.PutPixel(12 + position.x, 3 + position.y, 254, 221, 88);
		gfx.PutPixel(13 + position.x, 3 + position.y, 254, 221, 88);
		gfx.PutPixel(14 + position.x, 3 + position.y, 254, 221, 88);
		gfx.PutPixel(15 + position.x, 3 + position.y, 254, 221, 88);
		gfx.PutPixel(16 + position.x, 3 + position.y, 254, 221, 88);
		gfx.PutPixel(17 + position.x, 3 + position.y, 0, 0, 0);
		gfx.PutPixel(2 + position.x, 4 + position.y, 0, 0, 0);
		gfx.PutPixel(3 + position.x, 4 + position.y, 254, 221, 88);
		gfx.PutPixel(4 + position.x, 4 + position.y, 254, 221, 88);
		gfx.PutPixel(5 + position.x, 4 + position.y, 254, 221, 88);
		gfx.PutPixel(6 + position.x, 4 + position.y, 254, 221, 88);
		gfx.PutPixel(7 + position.x, 4 + position.y, 254, 221, 88);
		gfx.PutPixel(8 + position.x, 4 + position.y, 254, 221, 88);
		gfx.PutPixel(9 + position.x, 4 + position.y, 254, 221, 88);
		gfx.PutPixel(10 + position.x, 4 + position.y, 254, 221, 88);
		gfx.PutPixel(11 + position.x, 4 + position.y, 254, 221, 88);
		gfx.PutPixel(12 + position.x, 4 + position.y, 254, 221, 88);
		gfx.PutPixel(13 + position.x, 4 + position.y, 254, 221, 88);
		gfx.PutPixel(14 + position.x, 4 + position.y, 254, 221, 88);
		gfx.PutPixel(15 + position.x, 4 + position.y, 254, 221, 88);
		gfx.PutPixel(16 + position.x, 4 + position.y, 254, 221, 88);
		gfx.PutPixel(17 + position.x, 4 + position.y, 0, 0, 0);
		gfx.PutPixel(1 + position.x, 5 + position.y, 0, 0, 0);
		gfx.PutPixel(2 + position.x, 5 + position.y, 254, 221, 88);
		gfx.PutPixel(3 + position.x, 5 + position.y, 0, 0, 0);
		gfx.PutPixel(4 + position.x, 5 + position.y, 0, 0, 0);
		gfx.PutPixel(5 + position.x, 5 + position.y, 254, 221, 88);
		gfx.PutPixel(6 + position.x, 5 + position.y, 254, 221, 88);
		gfx.PutPixel(7 + position.x, 5 + position.y, 254, 221, 88);
		gfx.PutPixel(8 + position.x, 5 + position.y, 254, 221, 88);
		gfx.PutPixel(9 + position.x, 5 + position.y, 254, 221, 88);
		gfx.PutPixel(10 + position.x, 5 + position.y, 254, 221, 88);
		gfx.PutPixel(11 + position.x, 5 + position.y, 0, 0, 0);
		gfx.PutPixel(12 + position.x, 5 + position.y, 0, 0, 0);
		gfx.PutPixel(13 + position.x, 5 + position.y, 0, 0, 0);
		gfx.PutPixel(14 + position.x, 5 + position.y, 0, 0, 0);
		gfx.PutPixel(15 + position.x, 5 + position.y, 254, 221, 88);
		gfx.PutPixel(16 + position.x, 5 + position.y, 254, 221, 88);
		gfx.PutPixel(17 + position.x, 5 + position.y, 254, 221, 88);
		gfx.PutPixel(18 + position.x, 5 + position.y, 0, 0, 0);
		gfx.PutPixel(1 + position.x, 6 + position.y, 0, 0, 0);
		gfx.PutPixel(2 + position.x, 6 + position.y, 0, 0, 0);
		gfx.PutPixel(3 + position.x, 6 + position.y, 255, 255, 255);
		gfx.PutPixel(4 + position.x, 6 + position.y, 0, 0, 0);
		gfx.PutPixel(5 + position.x, 6 + position.y, 0, 0, 0);
		gfx.PutPixel(6 + position.x, 6 + position.y, 254, 221, 88);
		gfx.PutPixel(7 + position.x, 6 + position.y, 254, 221, 88);
		gfx.PutPixel(8 + position.x, 6 + position.y, 254, 221, 88);
		gfx.PutPixel(9 + position.x, 6 + position.y, 254, 221, 88);
		gfx.PutPixel(10 + position.x, 6 + position.y, 0, 0, 0);
		gfx.PutPixel(11 + position.x, 6 + position.y, 255, 255, 255);
		gfx.PutPixel(12 + position.x, 6 + position.y, 255, 255, 255);
		gfx.PutPixel(13 + position.x, 6 + position.y, 0, 0, 0);
		gfx.PutPixel(14 + position.x, 6 + position.y, 0, 0, 0);
		gfx.PutPixel(15 + position.x, 6 + position.y, 0, 0, 0);
		gfx.PutPixel(16 + position.x, 6 + position.y, 254, 221, 88);
		gfx.PutPixel(17 + position.x, 6 + position.y, 254, 221, 88);
		gfx.PutPixel(18 + position.x, 6 + position.y, 0, 0, 0);
		gfx.PutPixel(0 + position.x, 7 + position.y, 0, 0, 0);
		gfx.PutPixel(1 + position.x, 7 + position.y, 0, 0, 0);
		gfx.PutPixel(2 + position.x, 7 + position.y, 255, 255, 255);
		gfx.PutPixel(3 + position.x, 7 + position.y, 255, 255, 255);
		gfx.PutPixel(4 + position.x, 7 + position.y, 0, 0, 0);
		gfx.PutPixel(5 + position.x, 7 + position.y, 0, 0, 0);
		gfx.PutPixel(6 + position.x, 7 + position.y, 254, 221, 88);
		gfx.PutPixel(7 + position.x, 7 + position.y, 254, 221, 88);
		gfx.PutPixel(8 + position.x, 7 + position.y, 254, 221, 88);
		gfx.PutPixel(9 + position.x, 7 + position.y, 254, 221, 88);
		gfx.PutPixel(10 + position.x, 7 + position.y, 0, 0, 0);
		gfx.PutPixel(11 + position.x, 7 + position.y, 255, 255, 255);
		gfx.PutPixel(12 + position.x, 7 + position.y, 255, 255, 255);
		gfx.PutPixel(13 + position.x, 7 + position.y, 0, 0, 0);
		gfx.PutPixel(14 + position.x, 7 + position.y, 0, 0, 0);
		gfx.PutPixel(15 + position.x, 7 + position.y, 0, 0, 0);
		gfx.PutPixel(16 + position.x, 7 + position.y, 254, 221, 88);
		gfx.PutPixel(17 + position.x, 7 + position.y, 254, 221, 88);
		gfx.PutPixel(18 + position.x, 7 + position.y, 254, 221, 88);
		gfx.PutPixel(19 + position.x, 7 + position.y, 0, 0, 0);
		gfx.PutPixel(0 + position.x, 8 + position.y, 0, 0, 0);
		gfx.PutPixel(1 + position.x, 8 + position.y, 0, 0, 0);
		gfx.PutPixel(2 + position.x, 8 + position.y, 255, 255, 255);
		gfx.PutPixel(3 + position.x, 8 + position.y, 255, 255, 255);
		gfx.PutPixel(4 + position.x, 8 + position.y, 255, 255, 255);
		gfx.PutPixel(5 + position.x, 8 + position.y, 0, 0, 0);
		gfx.PutPixel(6 + position.x, 8 + position.y, 254, 221, 88);
		gfx.PutPixel(7 + position.x, 8 + position.y, 254, 221, 88);
		gfx.PutPixel(8 + position.x, 8 + position.y, 254, 221, 88);
		gfx.PutPixel(9 + position.x, 8 + position.y, 254, 221, 88);
		gfx.PutPixel(10 + position.x, 8 + position.y, 0, 0, 0);
		gfx.PutPixel(11 + position.x, 8 + position.y, 255, 255, 255);
		gfx.PutPixel(12 + position.x, 8 + position.y, 255, 255, 255);
		gfx.PutPixel(13 + position.x, 8 + position.y, 255, 255, 255);
		gfx.PutPixel(14 + position.x, 8 + position.y, 255, 255, 255);
		gfx.PutPixel(15 + position.x, 8 + position.y, 0, 0, 0);
		gfx.PutPixel(16 + position.x, 8 + position.y, 254, 221, 88);
		gfx.PutPixel(17 + position.x, 8 + position.y, 254, 221, 88);
		gfx.PutPixel(18 + position.x, 8 + position.y, 254, 221, 88);
		gfx.PutPixel(19 + position.x, 8 + position.y, 0, 0, 0);
		gfx.PutPixel(0 + position.x, 9 + position.y, 0, 0, 0);
		gfx.PutPixel(1 + position.x, 9 + position.y, 254, 221, 88);
		gfx.PutPixel(2 + position.x, 9 + position.y, 0, 0, 0);
		gfx.PutPixel(3 + position.x, 9 + position.y, 0, 0, 0);
		gfx.PutPixel(4 + position.x, 9 + position.y, 0, 0, 0);
		gfx.PutPixel(5 + position.x, 9 + position.y, 0, 0, 0);
		gfx.PutPixel(6 + position.x, 9 + position.y, 254, 221, 88);
		gfx.PutPixel(7 + position.x, 9 + position.y, 254, 221, 88);
		gfx.PutPixel(8 + position.x, 9 + position.y, 254, 221, 88);
		gfx.PutPixel(9 + position.x, 9 + position.y, 254, 221, 88);
		gfx.PutPixel(10 + position.x, 9 + position.y, 254, 221, 88);
		gfx.PutPixel(11 + position.x, 9 + position.y, 0, 0, 0);
		gfx.PutPixel(12 + position.x, 9 + position.y, 0, 0, 0);
		gfx.PutPixel(13 + position.x, 9 + position.y, 0, 0, 0);
		gfx.PutPixel(14 + position.x, 9 + position.y, 0, 0, 0);
		gfx.PutPixel(15 + position.x, 9 + position.y, 254, 221, 88);
		gfx.PutPixel(16 + position.x, 9 + position.y, 254, 221, 88);
		gfx.PutPixel(17 + position.x, 9 + position.y, 254, 221, 88);
		gfx.PutPixel(18 + position.x, 9 + position.y, 254, 221, 88);
		gfx.PutPixel(19 + position.x, 9 + position.y, 0, 0, 0);
		gfx.PutPixel(0 + position.x, 10 + position.y, 0, 0, 0);
		gfx.PutPixel(1 + position.x, 10 + position.y, 254, 221, 88);
		gfx.PutPixel(2 + position.x, 10 + position.y, 254, 221, 88);
		gfx.PutPixel(3 + position.x, 10 + position.y, 254, 221, 88);
		gfx.PutPixel(4 + position.x, 10 + position.y, 254, 221, 88);
		gfx.PutPixel(5 + position.x, 10 + position.y, 254, 221, 88);
		gfx.PutPixel(6 + position.x, 10 + position.y, 254, 221, 88);
		gfx.PutPixel(7 + position.x, 10 + position.y, 254, 221, 88);
		gfx.PutPixel(8 + position.x, 10 + position.y, 254, 221, 88);
		gfx.PutPixel(9 + position.x, 10 + position.y, 254, 221, 88);
		gfx.PutPixel(10 + position.x, 10 + position.y, 254, 221, 88);
		gfx.PutPixel(11 + position.x, 10 + position.y, 254, 221, 88);
		gfx.PutPixel(12 + position.x, 10 + position.y, 254, 221, 88);
		gfx.PutPixel(13 + position.x, 10 + position.y, 254, 221, 88);
		gfx.PutPixel(14 + position.x, 10 + position.y, 254, 221, 88);
		gfx.PutPixel(15 + position.x, 10 + position.y, 254, 221, 88);
		gfx.PutPixel(16 + position.x, 10 + position.y, 254, 221, 88);
		gfx.PutPixel(17 + position.x, 10 + position.y, 254, 221, 88);
		gfx.PutPixel(18 + position.x, 10 + position.y, 254, 221, 88);
		gfx.PutPixel(19 + position.x, 10 + position.y, 0, 0, 0);
		gfx.PutPixel(0 + position.x, 11 + position.y, 0, 0, 0);
		gfx.PutPixel(1 + position.x, 11 + position.y, 254, 221, 88);
		gfx.PutPixel(2 + position.x, 11 + position.y, 254, 221, 88);
		gfx.PutPixel(3 + position.x, 11 + position.y, 254, 221, 88);
		gfx.PutPixel(4 + position.x, 11 + position.y, 254, 221, 88);
		gfx.PutPixel(5 + position.x, 11 + position.y, 254, 221, 88);
		gfx.PutPixel(6 + position.x, 11 + position.y, 254, 221, 88);
		gfx.PutPixel(7 + position.x, 11 + position.y, 20, 14, 18);
		gfx.PutPixel(8 + position.x, 11 + position.y, 18, 11, 14);
		gfx.PutPixel(9 + position.x, 11 + position.y, 18, 12, 14);
		gfx.PutPixel(10 + position.x, 11 + position.y, 18, 12, 14);
		gfx.PutPixel(11 + position.x, 11 + position.y, 21, 13, 16);
		gfx.PutPixel(12 + position.x, 11 + position.y, 24, 11, 15);
		gfx.PutPixel(13 + position.x, 11 + position.y, 0, 0, 0);
		gfx.PutPixel(14 + position.x, 11 + position.y, 254, 221, 88);
		gfx.PutPixel(15 + position.x, 11 + position.y, 254, 221, 88);
		gfx.PutPixel(16 + position.x, 11 + position.y, 254, 221, 88);
		gfx.PutPixel(17 + position.x, 11 + position.y, 254, 221, 88);
		gfx.PutPixel(18 + position.x, 11 + position.y, 254, 221, 88);
		gfx.PutPixel(19 + position.x, 11 + position.y, 0, 0, 0);
		gfx.PutPixel(0 + position.x, 12 + position.y, 0, 0, 0);
		gfx.PutPixel(1 + position.x, 12 + position.y, 254, 221, 88);
		gfx.PutPixel(2 + position.x, 12 + position.y, 254, 221, 88);
		gfx.PutPixel(3 + position.x, 12 + position.y, 254, 221, 88);
		gfx.PutPixel(4 + position.x, 12 + position.y, 254, 221, 88);
		gfx.PutPixel(5 + position.x, 12 + position.y, 254, 221, 88);
		gfx.PutPixel(6 + position.x, 12 + position.y, 23, 9, 23);
		gfx.PutPixel(7 + position.x, 12 + position.y, 135, 26, 68);
		gfx.PutPixel(8 + position.x, 12 + position.y, 135, 26, 68);
		gfx.PutPixel(9 + position.x, 12 + position.y, 135, 26, 68);
		gfx.PutPixel(10 + position.x, 12 + position.y, 135, 26, 68);
		gfx.PutPixel(11 + position.x, 12 + position.y, 135, 26, 68);
		gfx.PutPixel(12 + position.x, 12 + position.y, 135, 26, 68);
		gfx.PutPixel(13 + position.x, 12 + position.y, 135, 26, 68);
		gfx.PutPixel(14 + position.x, 12 + position.y, 0, 0, 0);
		gfx.PutPixel(15 + position.x, 12 + position.y, 254, 221, 88);
		gfx.PutPixel(16 + position.x, 12 + position.y, 254, 221, 88);
		gfx.PutPixel(17 + position.x, 12 + position.y, 254, 221, 88);
		gfx.PutPixel(18 + position.x, 12 + position.y, 254, 221, 88);
		gfx.PutPixel(19 + position.x, 12 + position.y, 0, 0, 0);
		gfx.PutPixel(1 + position.x, 13 + position.y, 0, 0, 0);
		gfx.PutPixel(2 + position.x, 13 + position.y, 254, 221, 88);
		gfx.PutPixel(3 + position.x, 13 + position.y, 254, 221, 88);
		gfx.PutPixel(4 + position.x, 13 + position.y, 254, 221, 88);
		gfx.PutPixel(5 + position.x, 13 + position.y, 0, 0, 0);
		gfx.PutPixel(6 + position.x, 13 + position.y, 135, 26, 68);
		gfx.PutPixel(7 + position.x, 13 + position.y, 135, 26, 68);
		gfx.PutPixel(8 + position.x, 13 + position.y, 135, 26, 68);
		gfx.PutPixel(9 + position.x, 13 + position.y, 135, 26, 68);
		gfx.PutPixel(10 + position.x, 13 + position.y, 135, 26, 68);
		gfx.PutPixel(11 + position.x, 13 + position.y, 135, 26, 68);
		gfx.PutPixel(12 + position.x, 13 + position.y, 135, 26, 68);
		gfx.PutPixel(13 + position.x, 13 + position.y, 135, 26, 68);
		gfx.PutPixel(14 + position.x, 13 + position.y, 135, 26, 68);
		gfx.PutPixel(15 + position.x, 13 + position.y, 0, 0, 0);
		gfx.PutPixel(16 + position.x, 13 + position.y, 254, 221, 88);
		gfx.PutPixel(17 + position.x, 13 + position.y, 254, 221, 88);
		gfx.PutPixel(18 + position.x, 13 + position.y, 0, 0, 0);
		gfx.PutPixel(1 + position.x, 14 + position.y, 0, 0, 0);
		gfx.PutPixel(2 + position.x, 14 + position.y, 254, 221, 88);
		gfx.PutPixel(3 + position.x, 14 + position.y, 254, 221, 88);
		gfx.PutPixel(4 + position.x, 14 + position.y, 0, 0, 0);
		gfx.PutPixel(5 + position.x, 14 + position.y, 135, 26, 68);
		gfx.PutPixel(6 + position.x, 14 + position.y, 135, 26, 68);
		gfx.PutPixel(7 + position.x, 14 + position.y, 135, 26, 68);
		gfx.PutPixel(8 + position.x, 14 + position.y, 135, 26, 68);
		gfx.PutPixel(9 + position.x, 14 + position.y, 251, 192, 224);
		gfx.PutPixel(10 + position.x, 14 + position.y, 251, 192, 224);
		gfx.PutPixel(11 + position.x, 14 + position.y, 251, 192, 224);
		gfx.PutPixel(12 + position.x, 14 + position.y, 251, 192, 224);
		gfx.PutPixel(13 + position.x, 14 + position.y, 135, 26, 68);
		gfx.PutPixel(14 + position.x, 14 + position.y, 135, 26, 68);
		gfx.PutPixel(15 + position.x, 14 + position.y, 0, 0, 0);
		gfx.PutPixel(16 + position.x, 14 + position.y, 254, 221, 88);
		gfx.PutPixel(17 + position.x, 14 + position.y, 254, 221, 88);
		gfx.PutPixel(18 + position.x, 14 + position.y, 0, 0, 0);
		gfx.PutPixel(2 + position.x, 15 + position.y, 0, 0, 0);
		gfx.PutPixel(3 + position.x, 15 + position.y, 254, 221, 88);
		gfx.PutPixel(4 + position.x, 15 + position.y, 0, 0, 0);
		gfx.PutPixel(5 + position.x, 15 + position.y, 135, 26, 68);
		gfx.PutPixel(6 + position.x, 15 + position.y, 135, 26, 68);
		gfx.PutPixel(7 + position.x, 15 + position.y, 135, 26, 68);
		gfx.PutPixel(8 + position.x, 15 + position.y, 251, 192, 224);
		gfx.PutPixel(9 + position.x, 15 + position.y, 251, 192, 224);
		gfx.PutPixel(10 + position.x, 15 + position.y, 251, 192, 224);
		gfx.PutPixel(11 + position.x, 15 + position.y, 251, 192, 224);
		gfx.PutPixel(12 + position.x, 15 + position.y, 251, 192, 224);
		gfx.PutPixel(13 + position.x, 15 + position.y, 251, 192, 224);
		gfx.PutPixel(14 + position.x, 15 + position.y, 135, 26, 68);
		gfx.PutPixel(15 + position.x, 15 + position.y, 0, 0, 0);
		gfx.PutPixel(16 + position.x, 15 + position.y, 254, 221, 88);
		gfx.PutPixel(17 + position.x, 15 + position.y, 0, 0, 0);
		gfx.PutPixel(2 + position.x, 16 + position.y, 0, 0, 0);
		gfx.PutPixel(3 + position.x, 16 + position.y, 254, 221, 88);
		gfx.PutPixel(4 + position.x, 16 + position.y, 0, 0, 0);
		gfx.PutPixel(5 + position.x, 16 + position.y, 135, 26, 68);
		gfx.PutPixel(6 + position.x, 16 + position.y, 135, 26, 68);
		gfx.PutPixel(7 + position.x, 16 + position.y, 135, 26, 68);
		gfx.PutPixel(8 + position.x, 16 + position.y, 251, 192, 224);
		gfx.PutPixel(9 + position.x, 16 + position.y, 251, 192, 224);
		gfx.PutPixel(10 + position.x, 16 + position.y, 251, 192, 224);
		gfx.PutPixel(11 + position.x, 16 + position.y, 251, 192, 224);
		gfx.PutPixel(12 + position.x, 16 + position.y, 251, 192, 224);
		gfx.PutPixel(13 + position.x, 16 + position.y, 251, 192, 224);
		gfx.PutPixel(14 + position.x, 16 + position.y, 135, 26, 68);
		gfx.PutPixel(15 + position.x, 16 + position.y, 0, 0, 0);
		gfx.PutPixel(16 + position.x, 16 + position.y, 254, 221, 88);
		gfx.PutPixel(17 + position.x, 16 + position.y, 0, 0, 0);
		gfx.PutPixel(3 + position.x, 17 + position.y, 0, 0, 0);
		gfx.PutPixel(4 + position.x, 17 + position.y, 0, 0, 0);
		gfx.PutPixel(5 + position.x, 17 + position.y, 0, 0, 0);
		gfx.PutPixel(6 + position.x, 17 + position.y, 0, 0, 0);
		gfx.PutPixel(7 + position.x, 17 + position.y, 0, 0, 0);
		gfx.PutPixel(8 + position.x, 17 + position.y, 0, 0, 0);
		gfx.PutPixel(9 + position.x, 17 + position.y, 0, 0, 0);
		gfx.PutPixel(10 + position.x, 17 + position.y, 0, 0, 0);
		gfx.PutPixel(11 + position.x, 17 + position.y, 0, 0, 0);
		gfx.PutPixel(12 + position.x, 17 + position.y, 0, 0, 0);
		gfx.PutPixel(13 + position.x, 17 + position.y, 0, 0, 0);
		gfx.PutPixel(14 + position.x, 17 + position.y, 0, 0, 0);
		gfx.PutPixel(15 + position.x, 17 + position.y, 0, 0, 0);
		gfx.PutPixel(16 + position.x, 17 + position.y, 0, 0, 0);
		gfx.PutPixel(5 + position.x, 18 + position.y, 0, 0, 0);
		gfx.PutPixel(6 + position.x, 18 + position.y, 0, 0, 0);
		gfx.PutPixel(7 + position.x, 18 + position.y, 254, 221, 88);
		gfx.PutPixel(8 + position.x, 18 + position.y, 254, 221, 88);
		gfx.PutPixel(9 + position.x, 18 + position.y, 254, 221, 88);
		gfx.PutPixel(10 + position.x, 18 + position.y, 254, 221, 88);
		gfx.PutPixel(11 + position.x, 18 + position.y, 254, 221, 88);
		gfx.PutPixel(12 + position.x, 18 + position.y, 254, 221, 88);
		gfx.PutPixel(13 + position.x, 18 + position.y, 0, 0, 0);
		gfx.PutPixel(14 + position.x, 18 + position.y, 0, 0, 0);
		gfx.PutPixel(7 + position.x, 19 + position.y, 0, 0, 0);
		gfx.PutPixel(8 + position.x, 19 + position.y, 0, 0, 0);
		gfx.PutPixel(9 + position.x, 19 + position.y, 0, 0, 0);
		gfx.PutPixel(10 + position.x, 19 + position.y, 0, 0, 0);
		gfx.PutPixel(11 + position.x, 19 + position.y, 0, 0, 0);
		gfx.PutPixel(12 + position.x, 19 + position.y, 0, 0, 0);
	}

Vector2 Dude::GetPosition() const {
	return position;
}

int Dude::GetWidth() const {
	return width;
}

int Dude::GetHeight() const {
	return height;
}
