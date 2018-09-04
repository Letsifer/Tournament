#include <string>
using namespace std;
#pragma once
class Team
{
public:
	int index;
	string title;
	Team();
	Team(int index, string title) {
		this->index = index;
		this->title = title;
	}
	~Team();
};

