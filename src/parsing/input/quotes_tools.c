/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** quotes_tools
*/

#include "parsing/input/quotes_tools.h"
#include <stdio.h>

int simple_quote_founder(char *str, int i, int a)
{
    if (str[i] == '`' || str[i] == '(' || str[i] == ')') {
        a = i;
        i++;
        for (; str[i] != '`' || str[i] == '(' || str[i] == ')'; i++) {
            if (str[i] == '\0') {
                i = a;
                return (i);
            }
        }
        return (i);
    }
    return (i);
}

int is_two_quote(char *str, int i)
{
    i++;
    for (; str[i] != '\0'; i++) {
        if (str[i] == '`' || str[i] == 34 || str[i] == '(' || str[i] == ')')
            return (1);
        else if (str[i] == '\0')
            return (0);
    }
    return (0);
}

int quote_index(char *str)
{
    for (int i = 0, a = 0, locker = 0; str[i] != '\0'; i++) {
        if (str[i] == '`' || str[i] == '(' || str[i] == ')')
            locker += 1;
        if (locker == 1)
            a++;
        if (locker == 2)
            return (a);
    }
    return (-1);
}

char *keep_backquotes(char *str)
{
    char *str2 = malloc(sizeof(char) * (quote_index(str) + 1));
    int j = 0;

    for (int i = 0, locker = 0; str[i] != '\0'; i++) {
        if (str[i] == '`' || str[i] == '(' || str[i] == ')') {
            locker += 1;
            i++;
        }
        if (locker == 1) {
            str2[j] = str[i];
            j++;
        }
        if (locker == 2) {
            str2[j] = '\0';
            return (str2);
        }
    }
    str2[j] = '\0';
    return (str2);
}

char *cpy_dquote(char *str2, char *str)
{
    int j = 0;
    int locker = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 34) {
            locker += 1;
            i++;
        }
        if (str[i] == '\0') {
            str2[j] = '\0';
            return (str2);
        }
        if (locker == 1) {
            str2[j] = str[i];
            j++;
        }
    }
    str2[j] = '\0';
    return (str2);
}
