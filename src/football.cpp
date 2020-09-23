#include <stdexcept>

#include "football.h"
#include "score.h"

Football::Football(TEAM away_team, TEAM home_team)
    : away_team_(away_team)
    , home_team_(home_team)
    {
	initscr();			/* Start curses mode 		*/
    int r = start_color();
	cbreak();			/* Line buffering disabled, Pass on everty thing to me 		*/
	keypad(stdscr, TRUE);
    if (has_colors() == FALSE) {
        endwin();
        throw std::logic_error("[PauseableTimer] Your terminal does not support color\n");
    }

    init_pair(SCORE_AREA, COLOR_BLACK, COLOR_WHITE);
    init_pair(FIELD_AREA, COLOR_WHITE, COLOR_GREEN);
    clear();

	away_score_ = new Score(getShortTeamName(away_team), Score::AWAY);
	clock_ = new Clock();
    field_ = new Field();
	home_score_ = new Score(getShortTeamName(home_team_), Score::HOME);
}

Football::~Football() {
    delete away_score_;
    delete clock_;
    delete field_;
    delete home_score_;
	endwin();
	refresh();
}

uint16_t Football::getScore(HOME_OR_AWAY home_or_away) {
    if (home_or_away == HOME) {
        return home_score_->getScore();
    } else {
        return away_score_->getScore();
    }
}

const char *Football::getShortTeamName(TEAM team) {
    static const char* SHORT_TEAM_NAMES[LAST_TEAM_PLACEHOLDER + 1] = {
        "NYG",
        "9ER",
        "LVR",
        "LAR",
        "???"
    };

    return SHORT_TEAM_NAMES[team];
}

uint8_t Football::getYardsToGo() {
    return clock_->getYardsToGo();
}

void Football::nextDown() {
    clock_->nextDown();
}

void Football::nextQuarter() {
    clock_->nextQuarter();
}

void Football::redraw() {
    away_score_->redraw();
    home_score_->redraw();
    clock_->redraw();
    field_->redraw();
}

void Football::setScore(HOME_OR_AWAY home_or_away, uint16_t score) {
    if (home_or_away == HOME) {
        home_score_->setScore(score);
    } else {
        away_score_->setScore(score);
    }
}

void Football::setYardsToGo(uint8_t yards_to_go) {
    clock_->setYardsToGo(yards_to_go);
}

void Football::startGameClock() {
    clock_->startGameClock();
}

void Football::startPlayClock() {
    clock_->startPlayClock();
}

void Football::stopGameClock() {
    clock_->stopGameClock();
}

void Football::stopPlayClock() {
    clock_->stopPlayClock();
}

void Football::takeTimeout(HOME_OR_AWAY home_or_away) {
    if (home_or_away == HOME) {
        home_score_->takeTimeout();
    } else {
        away_score_->takeTimeout();
    }
}