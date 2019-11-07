#pragma once

struct Vector2 {
	Vector2(int x, int y) :x(x), y(y) {};
	int x, y;
};

class Dude
{
public:
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	Dude(int x, int y);
	void ClampToScreen();
	void Draw(class Graphics& gfx) const;
	Vector2 GetPosition() const;
	int GetWidth() const;
	int GetHeight() const;
private:
	Vector2 position;
	static constexpr int width = 20;
	static constexpr int height = 20;
};