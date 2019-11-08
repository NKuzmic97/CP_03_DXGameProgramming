#pragma once
class Poo {
public:
	void Init(int in_x,int in_y, int in_vx, int in_vy);
	void Update();
	void Draw(class Graphics& gfx) const;
	bool TestCollision(const class Dude& dude) const;
private:
	int x;
	int y;
	int vx;
	int vy;
	static constexpr int width = 24;
	static constexpr int height = 24;
	bool isEaten = false;
	bool initalized = false;
};