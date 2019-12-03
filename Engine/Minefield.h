#pragma once
#include "SpriteCodex.h"

class Minefield {
	class Tile {
	public:
		enum class State {
			Hidden,
			Flagged,
			Revealed
		};
	public:
		void SpawnMine();
		void Draw(const class Vei2& screenPos,bool gameOver, class Graphics& gfx) const;
		void Reveal();
		void ToggleFlag();
		void SetNeighborBombsCount(int bombCount);

		bool IsFlagged() const;
		bool HasMine() const {
			return hasBomb;
		}
		bool IsRevealed() const {
			return state == State::Revealed; }
	private:
		State state = State::Hidden;
		bool hasBomb = false;
		int nNeighborBombs = -1;
	};

public:
	Minefield(const Vei2& center,int numMines);
	void OnClickReveal(const Vei2& screenPos);
	void OnFlagClick(const Vei2& screenPos);
	void Draw(class Graphics& gfx) const;
	RectI GetRect() const {
		return RectI(topLeft, width * SpriteCodex::tileSize, height * SpriteCodex::tileSize);
	}

private:
	Tile& TileAt(const class Vei2& gridPosition);
	const Tile& TileAt(const class Vei2& gridPosition) const;
	Vei2 ScreenToGrid(const Vei2& screenPos) const;
	int CountNeighborBombs(const Vei2& gridPos);
private:
	static constexpr int width = 20;
	static constexpr int height = 16;
	Vei2 topLeft;
	bool gameOver = false;
	Tile field[width * height];
};