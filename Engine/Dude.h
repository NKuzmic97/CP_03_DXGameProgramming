#pragma once

class Dude
{
public:
	void ClampToScreen();
	int x = 400;
	int y = 300;
	static constexpr int width = 20;
	static constexpr int height = 20;
	void Draw(class Graphics& gfx);
};