/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** line_editing
*/

#ifndef LINE_EDITING_H_
#define LINE_EDITING_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <signal.h>
#include <curses.h>
#include <term.h>
#include <unistd.h>

typedef struct shortcut_s
{
    char *move_cursor_begining;
    char *move_left;
    char *move_right;
    char *clear_line;
} shortcut_t;

static struct termios *get_term_save(void);
void close_termcaps(char c);
void start_termcaps(void);
shortcut_t *init_sc(void);

#endif /* !LINE_EDITING_H_ */
