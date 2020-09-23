
#include "football.h"
#include "team.h"

Team::Team(TEAM team) 
    : football_(&Football::no_football)
    , team_(team) {
}

Team::Team() 
    : football_(&Football::no_football)
    , team_(NINERS) {
}

Team::~Team() {

}

const char *Team::getShortName() {
    static const char* SHORT_TEAM_NAMES[LAST_TEAM_PLACEHOLDER + 1] = {
        "NYG",
        "9ER",
        "LVR",
        "LAR",
        "???"
    };

    return SHORT_TEAM_NAMES[team_];
}

void Team::setFootball(Football* football) {
    football_ = football;
}


Team Team::no_team = Team();