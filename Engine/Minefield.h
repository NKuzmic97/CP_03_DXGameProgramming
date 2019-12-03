#pragma once
#include "SpriteCodex.h"
#include "Sound.h"

class Minefield {
public:
	enum class State {
		Lost,
		Win,
		Playing
	};
	class Tile {
	public:
		enum class State {
			Hidden,
			Flagged,
			Revealed
		};
	public:
		void SpawnMine();
		void Draw(const class Vei2& screenPos,Minefield::State state, class Graphics& gfx) const;
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

public:
	Minefield(const Vei2& center,int numMines);
	void OnClickReveal(const Vei2& screenPos);
	void OnFlagClick(const Vei2& screenPos);
	void Draw(class Graphics& gfx) const;
	RectI GetRect() const {
		return RectI(topLeft, width * SpriteCodex::tileSize, height * SpriteCodex::tileSize);
	}
	State GetState() const;
private:
	Tile& TileAt(const class Vei2& gridPosition);
	const Tile& TileAt(const class Vei2& gridPosition) const;
	Vei2 ScreenToGrid(const Vei2& screenPos) const;
	int CountNeighborBombs(const Vei2& gridPos);
	bool GameIsWon() const;
private:
	static constexpr int width = 20;
	static constexpr int height = 16;
	static constexpr int borderThickness = 10;
	static constexpr Color borderColor = Colors::Blue;
	Sound sndLose = Sound(L"spayed.wav");
	Vei2 topLeft;
	State state = State::Playing;
	Tile field[width * height];
};
