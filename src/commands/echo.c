/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** echo
*/

#include "commands/echo.h"
#include "global.h"
#include "structures.h"

void echo(UNUSED shell_t *shell, char **av)
{
    int fd = FD_TO_WRITE(shell->redirect.fd_out);
    char fmt[2] = "";
    bool n = false;

    for (int i = 1; av[i]; i++) {
        if (!strcmp(av[i], "-n")) {
            n = true;
            fmt[0] = '\0';
            continue;
        }
        dprintf(fd, "%s%s", fmt, av[i]);
        fmt[0] = ' ';
    }
    if (!n)
        dprintf(fd, "\n");
}