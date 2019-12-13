#pragma once
#include <string>

class GameSettings {
public:
	GameSettings(const std::string& filename);
private:
	int tileSize;
	int boardWidth, boardHeight;
	int numPoison;
	int numFood;
	float speedupRate;
public:
	int GetTileSize() const;
	int GetBoardWidth() const;
	int GetBoardHeight() const;
	int GetNumPoison() const;
	int GetNumFood() const;
	float GetSpeedupRate() const;
};

