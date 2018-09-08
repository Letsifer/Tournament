#include "Team.h"
#include <string>
#include <time.h>
using namespace std;
#pragma once
class Game
{
	static const int MAX_GOALS = 8;
public:
	Team host;
	Team guest;
	int hostGoals, guestGoals;
	Game(Team host, Team guest) {
		this->host = host;
		this->guest = guest;
	}
	void playGame() {
		hostGoals = rand() % MAX_GOALS;
		guestGoals = rand() % MAX_GOALS;
		host.submitGameResult(hostGoals, guestGoals);
		guest.submitGameResult(guestGoals, hostGoals);
	}
	string showGameTitle() {
		return host.title + " - " + guest.title;
	}
	string showGameResult() {
		return host.title + " " + to_string(hostGoals) + ":" + to_string(guestGoals) + " " + guest.title;
	}
	~Game();
};

