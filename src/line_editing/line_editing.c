/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** line_editing
*/

#include "line_editing/line_editing.h"

void set_cursor_pos(shortcut_t *sc, int i)
{
    int x = 0;
    int y = 0;

    printf("\033[6n");
    scanf("\033[%d;%dR", &y, &x);
    for (; x < i; x++) {
        write(0, sc->move_right, strlen(sc->move_right));
    }
    for (; x > i + 1; x--) {
        write(0, sc->move_left, strlen(sc->move_left));
    }
}

char *fill_str(shortcut_t *sc, char *str, char *c)
{
    int x = 0;
    int y = 0;
    int i = strlen(str);
    int lenc = strlen(c);

    printf("\033[6n");
    scanf("\033[%d;%dR", &y, &x);
    str[i + 1] = '\0';
    for (; i >= x + lenc; i--) {
        str[i] = str[i - 1 - lenc];
    }
    for (; lenc > 0; lenc--) {
        str[i--] = c[lenc - 1];
    }
    write(0, sc->move_cursor_begining, strlen(sc->move_cursor_begining));
    write(0, sc->clear_line, strlen(sc->clear_line));
    write(1, str, strlen(str));
    set_cursor_pos(sc, x);
    return (str);
}

char *read_input(void)
{
    shortcut_t *sc = init_sc();
    char *str = malloc(sizeof(char) * 1000);
    char c[100];
    ssize_t len = 0;

    for (str[0] = '\0'; 1;) {
        len = read(0, c, 99);
        if (len == 1) {
            c[len] = '\0';
            close_termcaps(*c);
            if ((*c == '\0' || *c == '\n') && len == 1)
                break;
            str = fill_str(sc, str, c);
        } else if (len != 0)
            write(1, c, len);
    }
    return (str);
}

int main(int ac, char **av)
{
    char *input = NULL;

    start_termcaps();
    while (1) {
        input = read_input();
        write(1, "\n", 1);
    }
    return (0);
}