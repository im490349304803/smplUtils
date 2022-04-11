#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <ncurses.h>
void draw_borders(WINDOW *screen) {
    int x, y, i;

    getmaxyx(screen, y, x);

    // 4 corners
    mvwprintw(screen, 0, 0, "+");
    mvwprintw(screen, y - 1, 0, "+");
    mvwprintw(screen, 0, x - 1, "+");
    mvwprintw(screen, y - 1, x - 1, "+");

    // sides
    for (i = 1; i < (y - 1); i++) {
        mvwprintw(screen, i, 0, "|");
        mvwprintw(screen, i, x - 1, "|");
    }

    // top and bottom
    for (i = 1; i < (x - 1); i++) {
        mvwprintw(screen, 0, i, "-");
        mvwprintw(screen, y - 1, i, "-");
    }
}


enum etxt {
    toup,
    tolow
};

int mainwin(enum etxt cnv) {
    int parent_x, parent_y, new_x, new_y;
    int woutput_size = 10;

    initscr();
    noecho();
    curs_set(FALSE);

    // set up initial windows
    getmaxyx(stdscr, parent_y, parent_x);
    woutput_size = parent_y / 2;

    WINDOW *winput = newwin(parent_y - woutput_size, parent_x, 0, 0);
    WINDOW *woutput = newwin(woutput_size, parent_x, parent_y - woutput_size, 0);

    draw_borders(winput);
    draw_borders(woutput);

    wmove(woutput, 2, 1);
    wmove(winput, 2, 1);
    while(1) {
        getmaxyx(stdscr, new_y, new_x);
        woutput_size = parent_y / 2;

        if (new_y != parent_y || new_x != parent_x) {
            parent_x = new_x;
            parent_y = new_y;

            wresize(winput, new_y - woutput_size, new_x);
            wresize(woutput, woutput_size, new_x);
            mvwin(woutput, new_y - woutput_size, 0);

            wclear(stdscr);
            wclear(winput);
            wclear(woutput);

            draw_borders(winput);
            draw_borders(woutput);
        }

        // usercode
        int winput_y, winput_x;
        int woutput_y, woutput_x;
        char c = getch();
        wprintw(winput, "%c", c);
        switch(cnv) {
            case toup:
                wprintw(woutput, "%c", toupper(c));
                break;
            default:
                wprintw(woutput, "%c", tolower(c));
                break;
        };
        getyx(winput, winput_y, winput_x);
        getyx(woutput, woutput_y, woutput_x);
        if(winput_x > new_x) {
            winput_x = 1;
            winput_y ++;
        }
        if(woutput_x > new_x) {
            woutput_x = 1;
            woutput_y ++;
        }
        if(woutput_y > new_y / 2) {
            wmove(woutput, 2, 1);
            wmove(winput, 2, 1);
        }

        // draw to our windows
        mvwprintw(winput, 1, 1, "input");
        mvwprintw(woutput, 1, 1, "output");
        wmove(winput, winput_y, winput_x);
        wmove(woutput, woutput_y, woutput_x);

        // refresh each window
        wrefresh(winput);
        wrefresh(woutput);
    }

    endwin();

    return 0;
}
