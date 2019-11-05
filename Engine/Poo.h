#pragma once

class Poo {
public:
	void Update();
public:
	static constexpr int width = 24, height = 24;
	int x, y;
	int vx, vy;
	bool IsEaten = false;
};