#include "team.h"

#include "player.h"

Player::Player(Team& team, POSITION position)
    : position_(position)
    , team_(team) {

}

Player::~Player() {

}

char Player::displayCharacter() {
    switch (position_) {
        case REGULAR:
            return 'd';

        case QUARTERBACK:
            return 'Q';
        
        case RECIEVER:
            return 'R';

        default:
            return '?';
    };

}