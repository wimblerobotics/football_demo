#include "score.h"
#include <ncurses.h>

Score::Score(const char* team_name, HOME_OR_AWAY home_or_away) :
	team_name_(team_name),
	home_or_away_(home_or_away),
	start_x_(home_or_away == AWAY ? 0 : WINDOW_WIDTH),
	start_y_(0),
	rows_(4),
	columns_(WINDOW_WIDTH),
	score_(0),
	timeouts_remaining_(3) {
	window_ = newwin(rows_, columns_, start_y_, start_x_);
}

Score::~Score() {
	delwin(window_);
}

uint16_t Score::getScore() { return score_; }


void Score::redraw() {
	mvwprintw(window_, 1, 1, " %.3s %3d ", team_name_, score_);
	mvwprintw(window_, 2, 1, "          ");
	for (int i = 0; i < timeouts_remaining_; i++) {
		mvwprintw(window_, 2, (i * 2) + 2, "_");
	}

	box(window_, 0, 0);
	wrefresh(window_);
}


void Score::setScore(uint16_t score) {
	score_ = score;
}

void Score::takeTimeout() {
	if (timeouts_remaining_ > 0) --timeouts_remaining_;
}

