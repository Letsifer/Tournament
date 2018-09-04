#include<vector>
#include"Game.h"
#include"Team.h"
#include"Round.h"
using namespace std;
#pragma once
class Tournament
{
	/*
	Составление календаря, пока что для четного числа команд.
	*/
	void initTournamentCalendar() {
		int roundsNumber = teams.size() - 1;
		const int DEFAULT_VALUE = -1;
		pair<int, int>** calendar = new pair<int, int>*[roundsNumber];
		int gamesInRound = teams.size() / 2;
		for (int i = 0; i < roundsNumber; i++) {
			calendar[i] = new pair<int, int>[gamesInRound];
			for (int j = 0; j < gamesInRound; j++) {
				calendar[i][j] = make_pair(DEFAULT_VALUE, DEFAULT_VALUE);
			}
		}
		int lastTeamIndex = teams.size() - 1;
		for (int i = 0; i < roundsNumber; i++) {
			if (i % 2 == 0) {
				calendar[i][0].first = lastTeamIndex;
			}
			else {
				calendar[i][0].second = lastTeamIndex;
			}
		}
		for (int i = 0, currentIndex = 0; i < roundsNumber; i++) {
			for (int j = 0; j < gamesInRound; j++) {
				if (calendar[i][j].first == DEFAULT_VALUE) {
					calendar[i][j].first = currentIndex;
				}
				else {
					calendar[i][j].second = currentIndex;
				}
				currentIndex = (currentIndex + 1) % lastTeamIndex;
			}
		}
		for (int i = 0, currentIndex = lastTeamIndex - 1; i < roundsNumber; i++) {
			for (int j = 1; j < gamesInRound; j++) {
				calendar[i][j].second = currentIndex;
			}
			currentIndex = currentIndex == 0 ? lastTeamIndex - 1 : currentIndex - 1;
		}
		for (int i = 0; i < roundsNumber; i++) {
			Round currentRound(i + 1, teams.size());
			for (int j = 0; j < gamesInRound; j++) {
				Game game(teams.at(calendar[i][j].first), teams.at(calendar[i][j].second));
				currentRound.games.push_back(game);
			}
			rounds.push_back(currentRound);
		}
	}

public:
	vector<Team> teams;
	vector<Round> rounds;
	Tournament(vector<Team> teams) {
		this->teams = teams;
		rounds.reserve(teams.size() - 1);
		initTournamentCalendar();
	}
	string showCalendar() {
		string title = "Mega tournament\n";
		string roundText = "";
		for each (Round round in rounds) {
			roundText += round.showRound();
		}
		return title + roundText;
	}
	~Tournament();
};

