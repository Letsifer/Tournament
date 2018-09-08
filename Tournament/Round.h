#include<vector>
#include<string>
#include<functional>
#include"Game.h"
using namespace std;
#pragma once
class Round
{
	string getRoundString(function<string(Game game)> gamePrinter) {
		string title = "Round #" + std::to_string(roundNumber) + "\n";
		string gamesText = "";
		for each (Game game in games) {
			gamesText += gamePrinter(game) + "\n";
		}
		gamesText += "---------------------------------\n";
		return title + gamesText;
	}
public:
	int roundNumber;
	vector<Game> games;
	Round(int roundNumber, int teams) {
		this->roundNumber = roundNumber;
		games.reserve(teams / 2);
	}
	string showRound() {
		auto printCalenarMatch = [&](Game game) -> string {
			return game.showGameTitle();
		};
		return getRoundString(printCalenarMatch);
	}
	string playRoundsMatches() {
		auto printCalenarMatch = [&](Game game) -> string {
			game.playGame();
			return game.showGameResult();
		};
		return getRoundString(printCalenarMatch);
	}
	~Round();
};

