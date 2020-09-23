#pragma once

#include <stdint.h>

class Team;

class Player {
public:
    typedef enum ROLE {
        REGULAR,
        QUARTERBACK,
        RECIEVER,
    } ROLE;

    // Whether a player is playing offense or defense.
    typedef enum STRATEGY {
        DEFENSE,
        OFFENSE,
    } STRATEGY;

    Player(Team* team, ROLE position, STRATEGY stragety);
    Player(); // Cannot use empty contructor.
    ~Player();

    // Get the equivalent character to display for the player.
    char getDisplayCharacter();

    // Get player's role.
    ROLE getRole();

    // Get player's defense/offense strategy kind.
    STRATEGY getStragety();

    // Get X position relative to center of scrimmage.
    int16_t getX();

    // Get Y position relative to center of scrimmage.
    int16_t getY();

    // Set position relative to center of scrimmage.
    void setXY(int16_t x, int16_t y);

private:
    // Position of player.
    ROLE role_;

    STRATEGY stragety_;

    // Team of player.
    Team* team_;

    // X yards from center of scrimmage.
    int16_t x_; 

    // Y yards from center of scrimmage.
    int16_t y_; 
};