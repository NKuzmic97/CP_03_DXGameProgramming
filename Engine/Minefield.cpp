#include "Minefield.h"
#include <assert.h>
#include <random>
#include "Vei2.h"
#include "Graphics.h"

void Minefield::Tile::SpawnMine() {
	assert(!hasBomb);
	hasBomb = true;
}

void Minefield::Tile::Draw(const Vei2 & screenPos, Graphics & gfx) const {
	switch (state) {
		case State::Hidden:
			SpriteCodex::DrawTileButton(screenPos, gfx);
			break;
		case State::Flagged:
			SpriteCodex::DrawTileButton(screenPos, gfx);
			SpriteCodex::DrawTileFlag(screenPos, gfx);
			break;
		case State::Revealed:
			if (!hasBomb) {
				SpriteCodex::DrawTile0(screenPos, gfx);
			}
			else {
				SpriteCodex::DrawTileBomb(screenPos, gfx);
			}
			break;
	}
}

void Minefield::Tile::Reveal() {
	assert(state == State::Hidden);
	
	state = State::Revealed;
}

Minefield::Minefield(int numMines) {
	assert(numMines > 0 && numMines < width * height);

	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> xDist(0, width - 1);
	std::uniform_int_distribution<int> yDist(0, height - 1);

	for (int numSpawned = 0; numSpawned < numMines; numSpawned++) {
		Vei2 spawnPos;
		do {
			spawnPos = { xDist(rng), yDist(rng) };
		} while (TileAt(spawnPos).HasMine());

		TileAt(spawnPos).SpawnMine();
	}
}

void Minefield::Draw(Graphics& gfx) const {
	gfx.DrawRect(GetRect(), SpriteCodex::baseColor);

	for (Vei2 gridPos = { 0,0 }; gridPos.y < height; gridPos.y++) {
		for (gridPos.x = 0; gridPos.x < width; gridPos.x++) {
			TileAt(gridPos).Draw(gridPos * SpriteCodex::tileSize,gfx);
		}
	}
}

void Minefield::OnClickReveal(const Vei2 & screenPos) {
	const Vei2 gridPos = ScreenToGrid(screenPos);

	assert(gridPos.x >= 0 && gridPos.x < width && gridPos.y >= 0 && gridPos.y < height);

	Tile& tile = TileAt(gridPos);
	if (!tile.IsRevealed()) {
		tile.Reveal();
	}
}

Minefield::Tile& Minefield::TileAt(const Vei2 & gridPosition) {
	return field[gridPosition.y * width + gridPosition.x];
}

const Minefield::Tile& Minefield::TileAt(const Vei2 & gridPosition) const {
	return field[gridPosition.y * width + gridPosition.x];
}

Vei2 Minefield::ScreenToGrid(const Vei2 & screenPos) const {
	return screenPos / SpriteCodex::tileSize;
}
