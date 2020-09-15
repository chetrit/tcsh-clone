/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** clear_parse_tools
*/

#include "parsing/input/clear_parse_tools.h"

char *loop_clear(char *getline1, int a, char *str, int b)
{
    while (getline1[a] != '\0') {
        if (getline1[a] != ' ') {
            str[b] = getline1[a];
            a++;
            b++;
        }
        while (getline1[a] == ' ') {
            a++;
            if (getline1[a] == '\0') {
                str[b] = '\0';
                return (str);
            }
        }
        if (getline1[a - 1] == ' ') {
            str[b] = ' ';
            b++;
        }
    }
    str[b] = '\0';
    return (str);
}

int brut_loop(char **str2, int a)
{
    if ((*str2)[a - 1] == ' ') {
        (*str2)[a] = ';';
        a++;
        (*str2)[a] = ' ';
        a++;
    } else {
        (*str2)[a] = ' ';
        a++;
        (*str2)[a] = ';';
        a++;
        (*str2)[a] = ' ';
        a++;
    }
    return (a);
}

char *loop_unparse(char *str2, char *str)
{
    int a = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '&' && str[i + 1] == '\0') {
            str2[a] = '\0';
            return (str2);
        }
        if (str[0] == '&' && i == 0)
            i++;
        if (str[i] == '&') {
            a = brut_loop(&str2, a);
        }
        if (str[i] != '&') {
            str2[a] = str[i];
            a++;
        }
    }
    str2[a] = '\0';
    return (str2);
}

char *unparse_pv(char *str)
{
    char *str2;
    int index = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ')
            index += 5;
        if (str[i] != ' ' && str[i] != '&')
            index += 2;
    }
    str2 = malloc(sizeof(char) * index + 2);
    str2 = loop_unparse(str2, str);
    return (str2);
}