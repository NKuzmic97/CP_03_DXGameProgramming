#include "Minefield.h"
#include <assert.h>
#include <random>
#include "Vei2.h"
#include "Graphics.h"
#include <algorithm>

void Minefield::Tile::SpawnMine() {
	assert(!hasBomb);
	hasBomb = true;
}

void Minefield::Tile::Draw(const Vei2 & screenPos,bool gameOver, Graphics & gfx) const {
	if (!gameOver) {
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
				SpriteCodex::DrawTileNumber(screenPos, nNeighborBombs, gfx);
			}
			else {
				SpriteCodex::DrawTileBomb(screenPos, gfx);
			}
			break;
		}
	}
	else {
		switch (state) {
		case State::Hidden:
			if (hasBomb) {
				SpriteCodex::DrawTileBomb(screenPos, gfx);
			}
			SpriteCodex::DrawTileButton(screenPos, gfx);
			break;
		case State::Flagged:
			if (hasBomb) {
				SpriteCodex::DrawTileBomb(screenPos, gfx);
				SpriteCodex::DrawTileFlag(screenPos, gfx);
			}
			else {
				SpriteCodex::DrawTileBomb(screenPos, gfx);
				SpriteCodex::DrawTileCross(screenPos, gfx);
			}
			break;
		case State::Revealed:
			if (!hasBomb) {
				SpriteCodex::DrawTileNumber(screenPos, nNeighborBombs, gfx);
			}
			else {
				SpriteCodex::DrawTileBombRed(screenPos, gfx);
			}
			break;
		}
	}
}

void Minefield::Tile::Reveal() {
	assert(state == State::Hidden);
	
	state = State::Revealed;
}

void Minefield::Tile::ToggleFlag() {
	assert(!IsRevealed());

	if (state == State::Hidden) {
		state = State::Flagged;
	}
	else {
		state = State::Hidden;
	}
}

void Minefield::Tile::SetNeighborBombsCount(int bombCount) {
	assert(nNeighborBombs == -1);
	nNeighborBombs = bombCount;
}

bool Minefield::Tile::IsFlagged() const {
	return state == State::Flagged;
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

	for (Vei2 gridPos = { 0,0 }; gridPos.y < height; gridPos.y++) {
		for (gridPos.x = 0; gridPos.x < width; gridPos.x++) {
			TileAt(gridPos).SetNeighborBombsCount(CountNeighborBombs(gridPos));
		}
	}
}

void Minefield::Draw(Graphics& gfx) const {
	gfx.DrawRect(GetRect(), SpriteCodex::baseColor);

	for (Vei2 gridPos = { 0,0 }; gridPos.y < height; gridPos.y++) {
		for (gridPos.x = 0; gridPos.x < width; gridPos.x++) {
			TileAt(gridPos).Draw(gridPos * SpriteCodex::tileSize,gameOver,gfx);
		}
	}
}

void Minefield::OnClickReveal(const Vei2 & screenPos) {
	if(!gameOver){
	const Vei2 gridPos = ScreenToGrid(screenPos);

	assert(gridPos.x >= 0 && gridPos.x < width && gridPos.y >= 0 && gridPos.y < height);

	Tile& tile = TileAt(gridPos);
	if (!tile.IsRevealed() && !tile.IsFlagged()) {
		tile.Reveal();
		if (tile.HasMine()) {
			gameOver = true;
		}
	}
	}
}

void Minefield::OnFlagClick(const Vei2 & screenPos) {
	if(!gameOver){
	const Vei2 gridPos = ScreenToGrid(screenPos);

	assert(gridPos.x >= 0 && gridPos.x < width && gridPos.y >= 0 && gridPos.y < height);

	Tile& tile = TileAt(gridPos);
	if (!tile.IsRevealed()) {
		tile.ToggleFlag();
	}
	}
}

Minefield::Tile& Minefield::TileAt(const Vei2 & gridPosition) {
	return field[gridPosition.y * width + gridPosition.x];
}

const Minefield::Tile& Minefield::TileAt(const Vei2 & gridPosition) const {
	return field[gridPosition.y * width + gridPosition.x];
}

Vei2 Minefield::ScreenToGrid(const Vei2& screenPos) const {
	return screenPos / SpriteCodex::tileSize;
}

int Minefield::CountNeighborBombs(const Vei2& gridPos) {
	const int xStart = std::max(0, gridPos.x - 1);
	const int yStart = std::max(0, gridPos.y - 1);
	const int xEnd = std::min(width - 1, gridPos.x + 1);
	const int yEnd = std::min(height - 1, gridPos.y + 1);

	int count = 0;
	for (Vei2 gridPos = { xStart,yStart }; gridPos.y <= yEnd; gridPos.y++) {
		for (gridPos.x = xStart; gridPos.x <= xEnd; gridPos.x++) {
			if (TileAt(gridPos).HasMine()) {
				count++;
			}
		}
	}

	return count;
}
