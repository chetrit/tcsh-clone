/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** parse inhibitors for 42sh
*/

#include "parsing/parse_inhibitors.h"

#include <stdio.h>

char get_char_after_inhibitor(char c)
{
    for (int i = 0; i < 9; ++i) {
        if (ESCAPE_SEQUENCES[i].lettter == c) {
            return (ESCAPE_SEQUENCES[i].c);
        }
    }
    return (c);
}

char *parse_inhibitors(char *str)
{
    char *final = malloc(sizeof(char) * (strlen(str) + 1));
    int i = 0;
    int j = 0;

    for (; str[i] != '\0'; ++i) {
        if (str[i] == '\\') {
            final[j++] = get_char_after_inhibitor(str[i + 1]);
            i += 1;
        } else {
            final[j++] = str[i];
        }
    }
    final[j] = '\0';
    return (final);
}