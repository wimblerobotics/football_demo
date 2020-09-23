#include <ncurses.h>

#include "football.h"
#include "score.h"
#include "team.h"

Score::Score()
	: columns_(WINDOW_WIDTH)
	, home_or_away_(HOME)
	, rows_(4)
	, score_(0)
	, start_x_(0)
	, start_y_(0)
	, team_(Team::no_team)
	, timeouts_remaining_(0) {
}

Score::Score(Team& team, HOME_OR_AWAY home_or_away)
	: columns_(WINDOW_WIDTH)
	, home_or_away_(home_or_away)
	, rows_(4)
	, score_(0)
	, start_x_(home_or_away == AWAY ? 0 : WINDOW_WIDTH)
	, start_y_(0)
	, team_(team)
	, timeouts_remaining_(3) {
	window_ = newwin(rows_, columns_, start_y_, start_x_);
}

Score::~Score() {
	delwin(window_);
}

uint16_t Score::getScore() { return score_; }


void Score::redraw() {
    wattron(window_, COLOR_PAIR(Football::SCORE_AREA));
	mvwprintw(window_, 1, 1, " %.3s %3d ", team_.getShortName(), score_);
	mvwprintw(window_, 2, 1, "          ");
	for (int i = 0; i < timeouts_remaining_; i++) {
		mvwprintw(window_, 2, (i * 2) + 2, "_");
	}

	box(window_, 0, 0);
    wattroff(window_, COLOR_PAIR(Football::SCORE_AREA));
	wrefresh(window_);
}


void Score::setScore(uint16_t score) {
	score_ = score;
}

void Score::takeTimeout() {
	if (timeouts_remaining_ > 0) --timeouts_remaining_;
}

