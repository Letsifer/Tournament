#include <iostream>
#include<vector>
#include "TeamsReader.h"
#include "Tournament.h"
#include <time.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	TeamsReader reader;
	Tournament tournament(reader.getTeamsFromSource());
	while (true) {		
		string round = tournament.playNextRound();
		cout << round;
		cout << "Press any key to show next round, Esc for exit\n";
		char c = cin.get();
		if (c == 27) {
			exit(0);
		}
	}
	//system("pause");
}