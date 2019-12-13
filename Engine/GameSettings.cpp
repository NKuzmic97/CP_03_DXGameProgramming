#include "GameSettings.h"
#include <fstream>

GameSettings::GameSettings(const std::string& filename) {
	std::fstream in(filename);
	
	for(std::string line; std::getline(in,line); ) {
		if(line == "[Tile Size]") {
			in >> tileSize;

		}
		else if(line == "[Board Dimensions]") {
			in >> boardWidth >> boardHeight;
		}
		else if (line == "[Poison Amount]") {
			in >> numPoison;
		}
		else if (line == "[Food Amount]") {
			in >> numFood;
		}
		else if (line == "[Speedup Rate]") {
			in >> speedupRate;
		}
	}
}


int GameSettings::GetTileSize() const {
	return tileSize;
}


int GameSettings::GetBoardWidth() const {
	return boardWidth;
}

int GameSettings::GetBoardHeight() const {
	return boardHeight;
}


int GameSettings::GetNumPoison() const {
	return numPoison;
}

int GameSettings::GetNumFood() const {
	return numFood;
}


float GameSettings::GetSpeedupRate() const {
	return speedupRate;
}
