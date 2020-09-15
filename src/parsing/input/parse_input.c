/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** parse input main file
*/

#include "parsing/input/parse_input.h"
#include <stdio.h>
#include <string.h>

int my_malloc2(char *str, char *separators)
{
    int index = 0;

    for (int i = 0, j = 0; str[i] != '\0'; i++) {
        for (; separators[j] != '\0'; j++) {
            if (str[i] - 48 == separators[j] - 48) {
                return (index);
            }
        }
        index += 1;
        j = 0;
    }
    return (index);
}

int my_malloc1(char *str, char *separators)
{
    int index = 0;

    for (int i = 0, j = 0, a  = 0; str[i] != '\0'; i++) {
        i = simple_quote_founder(str, i, a);
        for (; separators[j] != '\0'; j++) {
            if (str[i] - 48 == separators[j] - 48 && str[i - 1]) {
                index += 1;
            }
        }
        j = 0;
    }
    return (index);
}

char *parse_for_backslash(char *str, char *str2, char *separators)
{
    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = 0; separators[j] != '\0'; j++) {
            if ((i != 0 && str[i - 1] == 92) && str[i] == separators[j])
                str2[i] = j + 48;
        }
    }
    return (str2);
}

char *unparse_for_backslash(char *str, char *separators)
{
    int locker = 0;
    char *str2;
    int k = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = 0; separators[j] != '\0'; j++) {
            if ((i != 0 && str[i - 1] == 92) && str[i] == j + 48) {
                str[i] = separators[j];
                locker = 1;
            }
        }
    } if (locker == 1) {
        str2 = malloc(sizeof(char) * strlen(str));
        for (int i = 0; str[i] != '\0'; i++, k++) {
            if (str[i] == 92)
                i++;
            str2[k] = str[i];
        }
        str2[k] = '\0';
        return (str2);
    } return (str);
}

char **parse_input(char *str, char *separators, char **env)
{
    char **pieces = malloc(sizeof(char *) * (my_malloc1(str, separators) + 2));
    char *str2 = strdup(str);
    int i = 0;

    str2 = parse_for_backslash(str, str2, separators);
    for (; i != (my_malloc1(str, separators) + 1); i++)
        pieces[i] = malloc(sizeof(char) * (my_malloc2(str, separators) + 1));
    pieces[i] = NULL;
    str2 = parse_str(separators, str2);
    pieces[0] = strtok(str2, separators);
    for (int x = 1; pieces[x] != NULL; x++)
        pieces[x] = strtok(NULL, separators);
    pieces = unparse_dstr(pieces, separators, env);
    for (int z = 0; pieces[z] != NULL; z++)
        pieces[z] = unparse_for_backslash(pieces[z], separators);
    return (pieces);
}
