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
		void Draw(const class Vei2& screenPos, class Graphics& gfx) const;
		void Reveal();

		bool HasMine() const {
			return hasBomb;
		}
		bool IsRevealed() const {
			return state == State::Revealed; }
	private:
		State state = State::Hidden;
		bool hasBomb = false;
	};

public:
	Minefield(int numMines);
	void Draw(class Graphics& gfx) const;
	RectI GetRect() const { 
		return RectI(0, width * SpriteCodex::tileSize, 0, height * SpriteCodex::tileSize); }

private:
	Tile& TileAt(const class Vei2& gridPosition);
	const Tile& TileAt(const class Vei2& gridPosition) const;

private:
	static constexpr int width = 20;
	static constexpr int height = 16;
	Tile field[width * height];
};