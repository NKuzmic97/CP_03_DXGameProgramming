#pragma once
#include "Graphics.h"

enum class DrawID : unsigned char {
	DUDE_ID = 0,
	POO_ID,
	TITLE_SCREEN,
	GAME_OVER
};

class Renderer {
public:
	Renderer(Graphics& gfx);
	void Draw(DrawID id,int x = 0, int y = 0,const void* object = nullptr);
private:
	Graphics& gfx;

	void DrawTitleScreen(int x, int y);
	void DrawGameOver(int x, int y);
	void DrawDude(int x, int y);
	void DrawPoo(int x, int y);
};
