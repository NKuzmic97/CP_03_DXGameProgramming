#include "Poo.h"
#include "Graphics.h"

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
