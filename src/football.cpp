#include <stdexcept>

#include "football.h"
#include "score.h"
#include "team.h"

Football::Football(Team& away_team, Team& home_team)
    : away_score_(new Score(away_team, Score::AWAY))
    , away_team_(away_team)
    , home_score_(new Score(home_team, Score::HOME))
    , home_team_(home_team)
    {
    
    away_team_.setFootball(this);
    home_team_.setFootball(this);
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

	away_score_ = new Score(away_team_, Score::AWAY);
	clock_ = new Clock();
    field_ = new Field();
	home_score_ = new Score(home_team_, Score::HOME);
}

Football::Football()
    : away_score_(new Score(Team::no_team, Score::AWAY))
    , away_team_(Team::no_team)
    , home_score_(new Score(Team::no_team, Score::HOME))
    , home_team_(Team::no_team) {
    away_team_.setFootball(this);
    home_team_.setFootball(this);
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

Football Football::no_football = Football();