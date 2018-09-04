#include<vector>
#include<string>
#include"Game.h"
using namespace std;
#pragma once
class Round
{
public:
	int roundNumber;
	vector<Game> games;
	Round(int roundNumber, int teams) {
		this->roundNumber = roundNumber;
		games.reserve(teams / 2);
	}
	string showRound() {
		string title = "Round #" + std::to_string(roundNumber) + "\n";
		string gamesText = "";
		for each (Game game in games){ 
			gamesText += game.showGameTitle() + "\n";
		}
		gamesText += "---------------------------------\n";
		return title + gamesText;
	}
	~Round();
};

