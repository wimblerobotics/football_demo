
#include <algorithm>

#include "field.h"
#include "football.h"
#include "player.h"
#include "team.h"

Team::Team(TEAM team)
    : color_(0)
    , football_(&Football::no_football)
    , team_(team) {
    createDefensivePlayers();
    createOffensivePlayers();
}

Team::Team() 
    : color_(0)
    , football_(&Football::no_football)
    , team_(NINERS) {
}

Team::~Team() {

}

typedef struct P {
    Player::ROLE r;
    int16_t x;
    int16_t y;
} P;

void Team::createDefensivePlayers() {
    P p[11] = {
        {Player::REGULAR, -2, -4},
        {Player::REGULAR, -5, -3},
        {Player::REGULAR, -1, -2},
        {Player::REGULAR, -1, -1},
        {Player::REGULAR, -1, 0},
        {Player::REGULAR, -5, 0},
        {Player::REGULAR, -1, 1},
        {Player::REGULAR, -1, 1},
        {Player::REGULAR, -2, 2},
        {Player::REGULAR, -5, 2},
        {Player::REGULAR, -3, 3},
    };

    defensive_players_ = std::vector<Player>(11);

    for (int i = 0; i < 11; i++) {
        defensive_players_[i] = Player(this, p[i].r,Player::DEFENSE);
        defensive_players_[i].setXY(p[i].x, p[i].y);
    }
}

void Team::createOffensivePlayers() {
    P p[11] = {
        {Player::RECIEVER, 3, -4},
        {Player::REGULAR, 2, -3},
        {Player::REGULAR, 1, -2},
        {Player::REGULAR, 1, -1},
        {Player::REGULAR, 1, 0},
        {Player::QUARTERBACK, 3, 0},
        {Player::REGULAR, 1, 1},
        {Player::REGULAR, 1, 1},
        {Player::REGULAR, 2, 2},
        {Player::REGULAR, 3, 3},
        {Player::REGULAR, 5, 0},
    };

    offensive_players_ = std::vector<Player>(11);

    for (int i = 0; i < 11; i++) {
        offensive_players_[i] = Player(this, p[i].r,Player::OFFENSE);
        offensive_players_[i].setXY(p[i].x, p[i].y);
    }
}

const std::vector<Player>& Team::getDefensivePlayers() {
    return defensive_players_;
}

const std::vector<Player>& Team::getOffensivePlayers() {
    return offensive_players_;
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

void Team::placeDefensivePlayers(Field& field) {
    auto players = getDefensivePlayers();
    std::for_each(players.begin(), 
                  players.end(), 
                  [&](Player player) {
                      field.placePlayer(player, color_);
                  }
                  );
}

void Team::placeOffensivePlayers(Field& field) {
    auto players = getOffensivePlayers();
    std::for_each(players.begin(), 
                  players.end(), 
                  [&](Player player) {
                      field.placePlayer(player, color_);
                  }
                  );
    
}

void Team::setColor(short color) {
    color_ = color;
}

void Team::setFootball(Football* football) {
    football_ = football;
}


Team Team::no_team = Team();