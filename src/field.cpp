#include <ncurses.h>

#include "field.h"
#include "football.h"

Field::Field() 
    : columns_(WINDOW_WIDTH)
    , rows_(WINDOW_HEIGHT)
    , start_x_(0)
    , start_y_(4) {
    window_ = newwin(rows_, columns_, start_y_, start_x_);
}

Field::~Field() {
    delwin(window_);
}

void Field::redraw() {
    char line[WINDOW_WIDTH + 1];
    const char *line_format =
        " %02d.."
        "xxxxxxxxxx"
        "|         "
        "|         "
        "|         "
        "|         "
        "|         "
        "|         "
        "|         "
        "|         "
        "|         "
        "|         "
        "|xxxxxxxxxx"
        "....";
    const char *hash_line_format =
        " %02d.."
        "xxxxxxxxxx"
        "|---------"
        "|---------"
        "|---------"
        "|---------"
        "|---------"
        "|---------"
        "|---------"
        "|---------"
        "|---------"
        "|---------"
        "|xxxxxxxxxx"
        "....";
    const char *yard_marker_line_format =
        " %02d.."
        "xxxxxxxxxx"
        "|        1"
        "|0       2"
        "|0       3"
        "|0       4"
        "|0       5"
        "|0       4"
        "|0       3"
        "|0       2"
        "|0       1"
        "|0        "
        "|xxxxxxxxxx"
        "....";
    wattron(window_, COLOR_PAIR(Football::FIELD_AREA));
    for (int row = 0; row < WINDOW_HEIGHT - 2; row++) {
        if ((row > 0) && ((row % 18) == 0)) {
            sprintf(line, hash_line_format, row);
        } else {
            if ((row == 5) || (row == 47)) {
                sprintf(line, yard_marker_line_format, row);
            } else {
                sprintf(line, line_format, row);
            }
        }
        
        mvwprintw(window_, row + 1, 0, line);
    }

    box(window_, 0, 0);
    wattroff(window_, COLOR_PAIR(Football::FIELD_AREA));
    wrefresh(window_);
}
