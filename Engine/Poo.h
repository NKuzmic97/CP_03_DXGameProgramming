#pragma once
class Poo
{
public:
	void Update();
	void Draw(class Graphics& gfx) const;
	void ProcessConsumption(const class Dude& dude);
	int x;
	int y;
	int vx;
	int vy;
	static constexpr int width = 24;
	static constexpr int height = 24;
	bool isEaten = false;
};