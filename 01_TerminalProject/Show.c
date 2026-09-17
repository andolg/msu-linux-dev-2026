#include <curses.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>

#define DX 7
#define DY 3
#define LINE_SIZE 1024

const char ESC_KEY = 27;


static int read_line(FILE *file, char *line, size_t size) {
    char *newline;
    int c;

    if (fgets(line, size, file) == NULL) {
        return 0;
    }

    newline = strchr(line, '\n');
    if (newline != NULL) {
        *newline = '\0';
    } else {
        while ((c = fgetc(file)) != '\n' && c != EOF);
    }

    return 1;
}

int main(int argc, char *argv[]) {
    FILE *file;
    WINDOW *frame, *win;
    char line[LINE_SIZE];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s FILE\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror(argv[1]);
        return 1;
    }

    setlocale(LC_ALL, "");
    initscr();
    noecho();
    cbreak();

    int frame_height = LINES - 2 * DY;
    int frame_width = COLS - 2 * DX;
    if (frame_height < 3 || frame_width < 4) {
        endwin();
        fprintf(stderr, "Terminal is too small\n");
        fclose(file);
        return 1;
    }

    frame = newwin(frame_height, frame_width, DY, DX);
    box(frame, 0, 0);
    mvwaddnstr(frame, 0, 2, argv[1], frame_width - 4);
    wrefresh(frame);

    int height = frame_height - 2;
    int width = frame_width - 2;
    win = newwin(height, width, DY + 1, DX + 1);
    keypad(win, TRUE);
    scrollok(win, TRUE);

    for (int row = 0; row < height && read_line(file, line, sizeof(line)); ++row){
        mvwaddnstr(win, row, 0, line, width - 1);
    }
    wrefresh(win);

    int c;
    while ((c = wgetch(win)) != ESC_KEY && c != ERR) {
        if (c == ' ' && read_line(file, line, sizeof(line))) {
            wscrl(win, 1);
            mvwaddnstr(win, height - 1, 0, line, width - 1);
            wrefresh(win);
        }
    }

    delwin(win);
    delwin(frame);
    endwin();
    fclose(file);
    return 0;
}
