#include "Team.h"
#include <string>
using namespace std;
#pragma once
class Game
{
public:
	Team host;
	Team guest;
	Game(Team host, Team guest) {
		this->host = host;
		this->guest = guest;
	}
	string showGameTitle() {
		return host.title + " - " + guest.title;
	}
	~Game();
};

