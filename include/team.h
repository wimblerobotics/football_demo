#pragma once

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

    // Get short string name of team.
    const char *getShortName();

    void setFootball(Football* football);

    static Team no_team;

protected:
    Team(); // Cannot use empty constructor.

private:
    // The football game.
    Football* football_;

    // The team.
    TEAM team_;
};