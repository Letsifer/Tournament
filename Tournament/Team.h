#include <string>
using namespace std;
#pragma once
class Team
{
	static const int POINTS_FOR_WIN = 3, POINTS_FOR_DRAW = 1;
public:
	int index;
	string title;
	//next variables should be moved to special place
	int place;
	int points;
	int scoringGoals;
	int missedGoals;
	int getGoalsDifference() const{
		return scoringGoals - missedGoals;
	}
	Team();
	Team(int index, string title) {
		this->index = index;
		this->title = title;
		points = scoringGoals = missedGoals = 0;
		place = index;
	}
	Team(const Team& other) {
		index = other.index;
		title = other.title;
		place = other.place;
		points = other.points;
		scoringGoals = other.scoringGoals;
		missedGoals = other.missedGoals;
	}
	void submitGameResult(int scoringGoalsInGame, int missedGoalsInGame) {
		this->scoringGoals += scoringGoalsInGame;
		this->missedGoals = missedGoalsInGame;
		if (scoringGoalsInGame > missedGoalsInGame) {
			points += POINTS_FOR_WIN;
		}
		else if (scoringGoalsInGame == missedGoalsInGame) {
			points += POINTS_FOR_DRAW;
		}
	}
	~Team();
};

