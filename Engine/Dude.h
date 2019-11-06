#pragma once
#include "MainWindow.h"
class Dude {
private:
	MainWindow& wnd;
	Graphics& gfx;
public:
	int x = 400, y = 300;
	int width = 20, height = 20;
public:
	Dude(MainWindow& wnd,Graphics& gfx);
	void Update();
	void Draw();
};

