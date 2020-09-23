#include "team.h"

#include "player.h"

Player::Player(Team* team, ROLE position, STRATEGY stragety)
    : role_(position)
    , stragety_(stragety)
    , team_(team)
    , x_(0)
    , y_(0) {

}

Player::Player()
    : role_(REGULAR)
    , stragety_(OFFENSE)
    , team_(&Team::no_team)
    , x_(0)
    , y_(0) {
}

Player::~Player() {

}

char Player::getDisplayCharacter() {
    switch (role_) {
        case REGULAR:
            return getStragety() == DEFENSE ? 'd' : 'o';

        case QUARTERBACK:
            return 'Q';
        
        case RECIEVER:
            return 'R';

        default:
            return '?';
    };
}

Player::ROLE Player::getRole() {
    return role_;
}

Player::STRATEGY Player::getStragety() {
    return stragety_;
}

int16_t Player::getX() {
    return x_;
}

int16_t Player::getY() {
    return y_;
}

void Player::setXY(int16_t x, int16_t y) {
    x_ = x;
    y_ = y;
}