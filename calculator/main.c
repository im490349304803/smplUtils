#include <ncurses.h>
#include <string.h>
extern long long fact(long long num);
extern const char* supported_s;
extern int calc(char*str, long long int*nump,char**errstr);
#define ERR_COLOR_PAIR  init_pair(1, COLOR_RED, COLOR_BLACK)
#define ERR_COLOR_SET   attrset(COLOR_PAIR(1))
#define ERR_COLOR_UNSET   attroff(COLOR_PAIR(1))
#define CLR_LINE(num) move((num), 1); clrtoeol()

#define ERR_STR 6
#define ERR_MSG(...) ERR_COLOR_SET;\
    mvprintw(ERR_STR, 2, __VA_ARGS__);\
        ERR_COLOR_UNSET
int main()
{
    initscr ( );
    char buff[100];
    ERR_COLOR_PAIR;
    do {
        mvprintw ( 1, 1,"CALCULATOR");
        mvprintw ( 2, 1,"SUPPORTED FUNCS ARE: %s", supported_s);
        mvprintw ( 3, 1,"EXAMPLE: 13!, 23/3, 16SQRT, ... ETC");
        mvprintw ( 4, 1,": ");
        memset(buff, 0, sizeof buff);
        int scanr = scanw("%s", buff);
        CLR_LINE(4);
        CLR_LINE(5);
        CLR_LINE(6);
        CLR_LINE(7);
        CLR_LINE(8);
        CLR_LINE(9);
        CLR_LINE(10);
        CLR_LINE(11);
        if (scanr == 1) {//scanw succeeded 
            mvprintw ( 5, 1,"INPUT:%s", buff);
            long long int result;
            char *err_s;
            if(!calc(buff, &result, &err_s)) {
                mvprintw ( 7, 1,"= %lld", result);
            } else {
                ERR_MSG("CALC ERROR: %s", err_s);
            }
        }
        else {
            ERR_MSG("INPUT ERROR");
        }
    } while (buff[0] != 'q' && buff[0] != 'Q');
    endwin ( );
    return 0;
}
