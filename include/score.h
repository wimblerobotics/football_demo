#pragma once

#include <curses.h>

class Score {
public:
	// A team can either be the home team or the away team.
	typedef enum HOME_OR_AWAY {
		HOME,
		AWAY
	} HOME_OR_AWAY;

	// Constructor.
	Score(const char* team_name, HOME_OR_AWAY home_or_away);

	// Destructor.
	~Score();

	// Get the score.
	uint16_t getScore();

    // Redraw the window.
	void redraw();

	// Set the score.
	void setScore(uint16_t score);

	// Take a timeout.
	void takeTimeout();

private:
    // Cannot create an empty Score object.
	Score() {};

    // Width of window.
	uint16_t columns_;

    // Is this the home or away team.
	HOME_OR_AWAY home_or_away_;

    // Height of window.
	uint16_t rows_;

    // The team score.
	uint16_t score_;

    // X-coordinate for window.
	uint16_t start_x_;

    // Y-coordinate for window.
	uint16_t start_y_;

	// Number of timeouts remaining;
	uint8_t timeouts_remaining_;

    // Name of team.
	const char* team_name_;

    // The ncurses window itself.
	WINDOW *window_;

	// Constants.
	static const uint8_t WINDOW_WIDTH = 11;
	static const uint8_t MAX_TIMEOUTS = 3;

};

