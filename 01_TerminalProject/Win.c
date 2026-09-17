#include <ncurses.h>
#include <locale.h>

#define DX 7

void main() {
    WINDOW *win;

    setlocale(LC_ALL, "");

    initscr();
    noecho();
    cbreak();
    printw("Окно:");
    refresh();

    win = newwin(LINES-2*DX, COLS-2*DX, DX, DX);
    keypad(win, TRUE);
    scrollok(win, TRUE);
    for (int c = wgetch(win); c != 27; c = wgetch(win)) {
        wprintw(win, "\nKey: %d, Name: %s", c, keyname(c));
    }
    delwin(win);
    endwin();
}