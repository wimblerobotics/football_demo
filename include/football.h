#pragma once

#include "clock.h"
#include "field.h"
#include "score.h"

class Team;

class Football {
public:
	// A team can either be the home team or the away team.
	typedef enum HOME_OR_AWAY {
		HOME,
		AWAY
	} HOME_OR_AWAY;

    // Constructor.
    Football(Team& away_team, Team& home_team);

    // Destructor.
    ~Football();

    // Get team score.
    uint16_t getScore(HOME_OR_AWAY home_or_away);

    // Get yards to go.
    uint8_t getYardsToGo();

    // Advance to next down.
    void nextDown();

    // Advance to next quarter.
    void nextQuarter();

    // Redraw screen.
    void redraw();

    // Set a team score.
    void setScore(HOME_OR_AWAY home_or_away, uint16_t score);

    // Set yards to go.
    void setYardsToGo(uint8_t yards_to_go);

    // Start game clock;
    void startGameClock();

    // Start play clock.
    void startPlayClock();

    // Stop game clock;
    void stopGameClock();

    // Stop play clock;
    void stopPlayClock();

    // Get team score.
    void takeTimeout(HOME_OR_AWAY home_or_away);

    static Football no_football;

    static const short SCORE_AREA = 1;
    static const short FIELD_AREA = 2;

protected:
    Football(); // Can create via empty constructor.

private:
    // Away score.
	Score* away_score_;
    
    // Away team.
    Team& away_team_;

    // Game clock.
	Clock* clock_;

    // The playing field.
    Field* field_;

    // Home score.    
	Score* home_score_;

    // Home team.
    Team& home_team_;
};