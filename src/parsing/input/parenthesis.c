/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** parenthesis file c
*/

#include "parsing/input/parenthesis.h"

void exec_command_parenthesis(char *command, char **env)
{
    shell_t shell;

    init_shell(&shell, env);
    shell.utils.input = command;
    loop_shell(&shell);
}