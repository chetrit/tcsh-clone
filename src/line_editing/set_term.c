/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** set_term
*/

#include "line_editing/line_editing.h"

static struct termios *get_term_save(void)
{
    static struct termios term;

    return (&term);
}

void close_termcaps(char c)
{
    if (c != 4) {
        return;
    }
    write(1, "\n", 1);
    tcsetattr(0, 0, get_term_save());
    exit(84);
}

void start_termcaps(void)
{
    struct termios  term;
    char *env;

    env = getenv("TERM");
    if (!env || tgetent(NULL, env) == ERR || tcgetattr(0, &term) == -1) {
        exit(84);
    }
    memcpy(get_term_save(), &term, sizeof(struct termios));
    term.c_lflag &= ~(ICANON | ECHO | ISIG);
    term.c_cc[VMIN] = 1;
    term.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSADRAIN, &term) == -1) {
        exit(84);
    }
}

shortcut_t *init_sc(void)
{
    shortcut_t *sc = malloc(sizeof(shortcut_t));

    if (!sc)
        exit(84);
    if ((sc->move_cursor_begining = tgetstr("cr", NULL)) == NULL)
        exit(84);
    if ((sc->move_left = tgetstr("le", NULL)) == NULL)
        exit(84);
    if ((sc->move_right = tgetstr("nd", NULL)) == NULL)
        exit(84);
    if ((sc->clear_line = tgetstr("cd", NULL)) == NULL)
        exit(84);
    return (sc);
}