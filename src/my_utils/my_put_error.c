/*
** EPITECH PROJECT, 2019
** my_put_error
** File description:
** prints a string in the error output
*/

#include <stdio.h>

void my_put_error(char const *str)
{
    dprintf(2, str);
}
