/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** exit command
*/

#include "commands/exit.h"

void exit_command(shell_t *shell, char **av)
{
    shell->utils.return_value = av[1] ? atoi(av[1]) % 256 : 0;
    shell->utils.exit = true;
}