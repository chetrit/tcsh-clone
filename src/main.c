/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** main
*/

#include "main.h"

int main(UNUSED int ac, UNUSED char **av, char **envp)
{
    shell_t shell;

    return (minishell(&shell, envp, isatty(0)));
}