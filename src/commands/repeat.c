/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** repeat command
*/

#include "commands/repeat.h"

void repeat(shell_t *shell, char **av)
{
    if (!av[1]) {
        dprintf(2, "repeat: Too few arguments.\n");
    } else
        for (int i = 0; i < atoi(av[1]); i++) {
            check_commands(shell, &av[2]);
    }
}
