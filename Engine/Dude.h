#pragma once
#include "Vector2.h"

class Dude {
public:
	void Update(const class Keyboard& kbd);

	inline Dude::Dude(int x, int y)
		:position(x, y) {}

	void ClampToScreen();
	void Draw(class Graphics& gfx) const;
	Vector2 GetPosition() const;
	int GetWidth() const;
	int GetHeight() const;
private:
	Vector2 position;
	static constexpr int speed = 2;
	static constexpr int width = 20;
	static constexpr int height = 20;
};