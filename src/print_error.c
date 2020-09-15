/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** print error function
*/

#include "print_error.h"

void print_error_path(char *name)
{
    struct stat sb;

    stat(name, &sb);
    if (S_ISDIR(sb.st_mode)) {
        dprintf(2, "%s: Permission denied.\n", name);
    } else {
        dprintf(2, "%s: Command not found.\n", name);
    }
}

void print_error(char *name, int err, bool more, bool even_more)
{
    struct stat sb;

    stat(name, &sb);
    if (S_ISDIR(sb.st_mode)) {
        dprintf(2, "%s: Permission denied.\n", name);
        return;
    }
    if (more) {
        my_put_error("./");
    }
    my_put_error(name);
    my_put_error(": ");
    if (!even_more) {
        dprintf(2, "%s\n", strerror(err));
    } else {
        dprintf(2, "%s.\n", strerror(err));
    }
}