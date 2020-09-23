#include <ncurses.h>
#include <pthread.h>
#include <stdexcept>


#include "clock.h"
#include "football.h"

//typedef void * (*THREADFUNCPTR)(void *);

Clock::Clock()
    : columns_(WINDOW_WIDTH)
    , down_(1)
    , quarter_(1)
    , rows_(4)
    , start_x_(22)
    , start_y_(0)
    , yards_to_go_(10) {
    game_clock_ = new PauseableTimer(SECONDS_PER_QUARTER);
    play_clock_ = new PauseableTimer(SECONDS_PER_PLAY);
	window_ = newwin(rows_, columns_, start_y_, start_x_);
}

Clock::~Clock() {
	delwin(window_);
}

uint8_t Clock::getDown() {
    return down_;
}

uint8_t Clock::getQuarter() {
    return quarter_;
}

uint8_t Clock::getYardsToGo() {
    return yards_to_go_;
}

uint16_t Clock::getRemainingPlayclockSeconds() {
    return play_clock_->getRemainingTime();
}

uint16_t Clock::getRemainingQuarterSeconds() {
    return game_clock_->getRemainingTime();
}

void Clock::nextDown() {
    if (down_ < 4) down_++;
}

void Clock::nextQuarter() {
    if (quarter_ < 4) quarter_++;
}

void Clock::redraw() {
    static const char *DOWN_NAMES[4] = {"1st", "2nd", "3rd", "4th"};
    static const char *QUARTER_NAMES[4] = {"1ST", "2ND", "3RD", "4TH"};
    uint16_t quarter_seconds_remaining = getRemainingQuarterSeconds();
    uint16_t playclock_seconds_remaining = getRemainingPlayclockSeconds();
    wattron(window_, COLOR_PAIR(Football::SCORE_AREA));
 	mvwprintw(window_
              , 1
              , 1
              , " %.3s %2d:%02d %2d "
              , QUARTER_NAMES[quarter_ - 1]
              , quarter_seconds_remaining / 60
              , quarter_seconds_remaining % 60
              , playclock_seconds_remaining);
    char line[33] = "                                ";
    sprintf(line, " %.3s & %d            ", DOWN_NAMES[down_ - 1], yards_to_go_);
    mvwprintw(window_
              , 2
              , 1
              , "%.14s"
              , line);
	box(window_, 0, 0);
    wattroff(window_, COLOR_PAIR(Football::SCORE_AREA));
	wrefresh(window_);
}

void Clock::resetPlayClock(uint8_t seconds_remaining) {
    play_clock_->resetTimer(SECONDS_PER_PLAY);
}

void Clock::setDown(uint8_t down) {
    down_ = down;
}

void Clock::setYardsToGo(uint8_t yards_to_go) {
    yards_to_go_ = yards_to_go;
}

void Clock::startGameClock() {
    game_clock_->start();
}

void Clock::startPlayClock() {
    play_clock_->start();
}

void Clock::stopGameClock() {
    game_clock_->stop();
}

void Clock::stopPlayClock() {
    play_clock_->stop();
}

