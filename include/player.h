#pragma once

#include "team.h"

class Player {
public:
    typedef enum POSITION {
        REGULAR,
        QUARTERBACK,
        RECIEVER,
    } POSITION;

    Player(Team& team, POSITION position);
    ~Player();

protected:
    Player(); // Cannot use empty contructor.

private:
    char displayCharacter();

    // Position of player.
    POSITION position_;

    // Team of player.
    Team& team_;
};