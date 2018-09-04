#include <iostream>
#include<vector>
#include "Team.h"
#include "Tournament.h"
using namespace std;

int main() {
	vector<Team> teams;
	int index = 1;
	teams.push_back(Team(index++, "Zenit"));
	teams.push_back(Team(index++, "CSKA"));
	teams.push_back(Team(index++, "Dinamo"));
	teams.push_back(Team(index++, "Spartak"));
	Tournament tournament(teams);
	string calendar = tournament.showCalendar();
	cout << calendar;
	system("pause");
}