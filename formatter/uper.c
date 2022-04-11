#include <ncurses.h>
#include <string.h>
#define ERR_COLOR_PAIR  init_pair(1, COLOR_RED, COLOR_BLACK)
#define ERR_COLOR_SET   attrset(COLOR_PAIR(1))
#define ERR_COLOR_UNSET   attroff(COLOR_PAIR(1))
#define CLR_LINE(num) move((num), 1); clrtoeol()

#define ERR_STR 6
#define ERR_MSG(...) ERR_COLOR_SET;\
    mvprintw(ERR_STR, 2, __VA_ARGS__);\
    ERR_COLOR_UNSET
enum etxt {
    toup,
    tolow
};


extern int mainwin(enum etxt cnv);
int main()
{
    mainwin(toup);
}
