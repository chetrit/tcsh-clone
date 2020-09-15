/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** get input function
*/

#include <stdio.h>
#include <stdlib.h>

#include "structures.h"

void get_input(shell_t *shell)
{
    size_t size = 0;
    int return_value = -1;

    return_value = getline(&shell->utils.input, &size, stdin);
    if (return_value == EOF || return_value == 0 || size == 0) {
        shell->utils.input = NULL;
        return;
    }
    if (shell->utils.input[return_value - 1] == '\n') {
        shell->utils.input[return_value - 1] = '\0';
    }
}