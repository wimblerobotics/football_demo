#pragma once

#include <vector>
#include "player.h"

class Field;
class Football;

class Team {
public:
    typedef enum TEAM {
        GIANTS,
        NINERS,
        RAIDERS,
        RAMS,
        LAST_TEAM_PLACEHOLDER
    } TEAM;

    Team(TEAM team);
    ~Team();

    // Get the defensive players for the team.
    const std::vector<Player>& getDefensivePlayers();

    // Get the offensive players for the team.
    const std::vector<Player>& getOffensivePlayers();

    // Get short string name of team.
    const char *getShortName();

    // Put the defense on the field.
    void placeDefensivePlayers(Field& field);

    // Put the offense on the field.
    void placeOffensivePlayers(Field& field);

    // Set team's color (index).
    void setColor(short color);

    void setFootball(Football* football);

    static Team no_team;

protected:
    Team(); // Cannot use empty constructor.

private:
    void createDefensivePlayers();
    void createOffensivePlayers();
    
    // Team color index.
    short color_;

    // The football game.
    Football* football_;

    // The team.
    TEAM team_;

    std::vector<Player> defensive_players_;
    std::vector<Player> offensive_players_;
};