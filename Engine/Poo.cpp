#include "Poo.h"
#include "Graphics.h"
#include <random>

Poo::Poo() {
	MovementRandomize();
	PositionRandomize();
}

void Poo::PositionRandomize() {
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> xDist(0, 770);
	std::uniform_int_distribution<int> yDist(0, 570);
	x = xDist(rng);
	y = yDist(rng);
}


void Poo::MovementRandomize() {
	int directions[] = { -1,1 };
	vx = directions[rand() % (sizeof(directions) / sizeof(int))];
	vy = directions[rand() % (sizeof(directions) / sizeof(int))];
}

void Poo::Update() {
	x += vx;
	y += vy;

	const int right = x + width;
	if (x < 0) {
		x = 0;
		vx *= -1;
	}
	else if (right >= Graphics::ScreenWidth) {
		x = (Graphics::ScreenWidth - 1) - width; 
		vx *= -1;
	}

	const int bottom = y + height;
	if (y < 0) {
		y = 0;
		vy *= -1;
	}
	else if (bottom >= Graphics::ScreenHeight) { 
		y = (Graphics::ScreenHeight - 1) - height; 
		vy *= -1;
	}

}