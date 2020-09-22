#include <assert.h>
#include <curses.h>
#include <iostream>
#include <string>
//#include <stdlib.h>
#include <unistd.h>                  /*  for sleep()  */

#include "football.h"


int main() {
	initscr();			/* Start curses mode 		*/
	cbreak();			/* Line buffering disabled, Pass on everty thing to me 		*/
	keypad(stdscr, TRUE);
	refresh();

	Football* football = new Football(Football::NINERS, Football::RAMS);

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
	endwin();
	refresh();
	return EXIT_SUCCESS;
}