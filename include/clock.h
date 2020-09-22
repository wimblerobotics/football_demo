#pragma once

#include <curses.h>
#include <pthread.h>
#include <string>

#include "pauseable_timer.h"

class Clock {
public:
	// Constructor.
	Clock();

	// Destructor;
	~Clock();

    // Get down.
    uint8_t getDown();

    // Get quarter.
    uint8_t getQuarter();

	// Get the seconds remaining in the quarter.
	uint16_t getRemainingQuarterSeconds();

	// Get the seconds remaining in the play.
    uint16_t getRemainingPlayclockSeconds();

    // Get yards to go.
    uint8_t getYardsToGo();

    // Advance to next down;
    void nextDown();

    // Advance to the next quarter.
    void nextQuarter();

    // Redraw the window.
	void redraw();

    // Reset play clock.
    void resetPlayClock(uint8_t seconds_remaining = SECONDS_PER_PLAY);

    // Set the down.
    void setDown(uint8_t down);

    // Set yards to go.
    void setYardsToGo(uint8_t yards_to_go);

	// Start the game clock.
	void startGameClock();

    // Start the play clock.
    void startPlayClock();

	// Stop the game clock.
	void stopGameClock();

    // Stop the play clock.
    void stopPlayClock();

private:
    // Width of window.
	uint16_t columns_;

    // Down.
    uint8_t down_;

    // The game clock;
    PauseableTimer* game_clock_;

    // Mutex to protect threaded access to state.
    pthread_mutex_t mutex_;

    // The play clock;
    PauseableTimer* play_clock_;

    // Quarter.
    uint8_t quarter_;

    // Height of window.
	uint16_t rows_;

    // X-coordinate for window.
	uint16_t start_x_;

    // Y-coordinate for window.
	uint16_t start_y_;

    // The ncurses window itself.
	WINDOW *window_;

    // Yards to go.
    uint8_t yards_to_go_;

	// Constants.
	static const uint8_t WINDOW_WIDTH = 16;
    static const uint16_t SECONDS_PER_PLAY = 40; // Seconds in play clock at start of play.
    static const uint16_t SECONDS_PER_QUARTER = 15 * 60; // Seconds in a quarter.

};

