#include <assert.h>
#include <curses.h>
#include <iostream>
#include <string>
//#include <stdlib.h>
#include <unistd.h>                  /*  for sleep()  */

#include "football.h"
#include "team.h"


int main() {
	Team away_team = Team(Team::NINERS);
	Team home_team = Team(Team::GIANTS);
	Football* football = new Football(away_team, home_team);

	football->setScore(Football::AWAY, 20);
	football->setScore(Football::HOME, 20);

	for (int i = 1; i < 20; i++) {
		if (i == 5) football->startGameClock();
		if (i == 10) football->stopGameClock();
		if ((i % 5) == 0) football->nextQuarter();
		if ((i % 4) == 0) football->nextDown();
		if ((i % 3) == 0) football->setYardsToGo(football->getYardsToGo() + 1);
		if (i == 7) football->startPlayClock();
		sleep(1);
		football->setScore(Football::AWAY, football->getScore(Football::AWAY) - 1);
		football->setScore(Football::HOME, football->getScore(Football::HOME) + 1);
		football->takeTimeout(Football::HOME);
		football->redraw();
	}

	delete football;
	return EXIT_SUCCESS;
}