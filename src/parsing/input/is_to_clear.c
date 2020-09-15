/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** is_to_clear
*/

#include "parsing/input/is_to_clear.h"

bool is_err(char *str)
{
    if (strlen(str) == 1 && str[0] == ';')
        return (true);
    return (false);
}

bool is_pv(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ';')
            return (true);
    }
    return (false);
}