#pragma once

#include "clock.h"
#include "score.h"

class Football {
public:
	// A team can either be the home team or the away team.
	typedef enum HOME_OR_AWAY {
		HOME,
		AWAY
	} HOME_OR_AWAY;

    typedef enum TEAM {
        GIANTS,
        NINERS,
        RAIDERS,
        RAMS,
        LAST_TEAM_PLACEHOLDER
    } TEAM;

    // Constructor.
    Football(TEAM away_team, TEAM home_team);

    // Destructor.
    ~Football();

    // Get team score.
    uint16_t getScore(HOME_OR_AWAY home_or_away);

    // Get short string name of team.
    const char *getShortTeamName(TEAM team);

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

protected:
    Football() {} // Can create via empty constructor.

private:
    // Away score.
	Score* away_score_ = new Score("9ERSxx", Score::AWAY);
    
    // Away team.
    TEAM away_team_;

    // Game clock.
	Clock* clock_ = new Clock();

    // Home score.    
	Score* home_score_ = new Score("ABCD", Score::HOME);

    // Home team.
    TEAM home_team_;
};