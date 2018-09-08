#include<vector>
#include <algorithm>
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
				currentIndex = currentIndex == 0 ? lastTeamIndex - 1 : currentIndex - 1;
			}			
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
	int currentRound = 0;
	int roundsNumber;
public:
	vector<Team> teams;
	vector<Round> rounds;
	Tournament(vector<Team> teams) {
		this->teams = teams;
		this->roundsNumber = teams.size() - 1;
		rounds.reserve(roundsNumber);
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
	string showCurrentTable() {
		sort(teams.begin(), teams.end(),
			[](const Team first, const Team second) -> bool 
		{
			if (first.points != second.points) {
				return first.points > second.points;
			}
			if (first.getGoalsDifference() > second.getGoalsDifference()) {
				return first.getGoalsDifference() > second.getGoalsDifference();
			}
			return first.scoringGoals > second.scoringGoals;
		});
		string tableHeader = "# Название Мячи Очки\n";
		string table = "";
		for (int i = 0; i < teams.size(); i++) {
			Team current = teams.at(i);
			current.place = i + 1;
			string str = to_string(current.place) + " " 
				+ current.title + " " 
				+ to_string(current.scoringGoals) + " " 
				+ to_string(current.missedGoals) + " " 
				+ to_string(current.points) + "\n";
			table += str;
		}
		return tableHeader + table;
	}
	string playNextRound() {
		if (currentRound >= roundsNumber) {
			return "Tournament is over";
		}
		Round round = rounds.at(currentRound);
		string matches = round.playRoundsMatches();
		string table = showCurrentTable();
		currentRound++;
		string roundHeader = currentRound == roundsNumber
			? "After all rounds. Tournament is over!\n"
			: "After " + to_string(currentRound) + " round\n";
		return roundHeader + matches + table;
	}
	~Tournament();
};

