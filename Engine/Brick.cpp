#include "Brick.h"

Brick::Brick(const RectF & rec_, Color color_) {
}

void Brick::Draw(Graphics & gfx) const {
	gfx.DrawRect(rect, color);
}
