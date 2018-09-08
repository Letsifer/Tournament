#include <iostream>
#include<vector>
#include "TeamsReader.h"
#include "Tournament.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	TeamsReader reader;
	Tournament tournament(reader.getTeamsFromSource());
	string calendar = tournament.showCalendar();
	cout << calendar;
	system("pause");
}