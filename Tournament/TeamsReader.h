#include "Team.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
#pragma once
class TeamsReader
{
public:
	TeamsReader();
	vector<Team> getTeamsFromSource() {
		ifstream inputStream;
		inputStream.open("teams.txt");
		if (!inputStream) {
			cerr << "Unable to find file!\n";
			system("pause");
			exit(1);
		}
		vector<Team> teams;
		int index = 1;
		for (string temp; getline(inputStream, temp); index++) {
			teams.push_back(Team(index, temp));
		}
		inputStream.close();
		return teams;
	}
	~TeamsReader();
};

