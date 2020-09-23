#pragma once

#include <curses.h>

class Player;

class Field {
public:
    Field();
    ~Field();

    void placePlayer(Player& player, short color);

    // Refresh the field window.
    void refresh();

    // Redraw the base field.
    void redraw();

private:
    // Width of window.
    uint16_t columns_;

    // Height of window.
    uint16_t rows_;

    // X-coordinate for window.
    uint16_t start_x_;

    // Y-coordinate for window.
    uint16_t start_y_;

    // The ncurses window itself.
    WINDOW* window_;

    // Constants.
    static const uint8_t WINDOW_HEIGHT = 55;
    static const uint8_t WINDOW_WIDTH = 131;
};