#include "Dude.h"

Dude::Dude(MainWindow& wnd):
	wnd(wnd){}

void Dude::Update() {
	if (wnd.kbd.KeyIsPressed(VK_UP))
		y -= 1;
	else if (wnd.kbd.KeyIsPressed(VK_DOWN))
		y += 1;
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
		x -= 1;
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		x += 1;

	const int right = x + width;
	if (x < 0)
		x = 0;
	else if (right >= Graphics::ScreenWidth)
		x = (Graphics::ScreenWidth - 1) - width;

	const int bottom = y + height;
	if (y < 0) y = 0;
	else if (bottom >= Graphics::ScreenHeight)
		y = (Graphics::ScreenHeight - 1) - height;
}
