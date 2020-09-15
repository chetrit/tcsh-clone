/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** clear_str
*/

#include "parsing/input/clear_arr.h"

int malloc_clear(char *str)
{
    int index = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ';')
            index += 2;
    }
    return (index);
}

char *clear_mystr(char *getline1)
{
    int a = 0;
    int b = 0;
    char *str;

    while (getline1[a] != '\0') {
        if (getline1[a] != ' ' || getline1[a] != '\t')
            b += 1;
        a++;
    }
    str = malloc(sizeof(char) * (b + 1));
    a = 0;
    b = 0;
    while (getline1[a] == ' ' || getline1[a] == '\t')
        a++;
    str = loop_clear(getline1, a, str, b);
    return (str);
}

char *parse_clear_arr(char *str)
{
    char *str2 = malloc(sizeof(char) * (malloc_clear(str)) + 1);
    int i = 0;
    int a = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] != ';') {
            str2[a] = str[i];
            a++;
        } else if (str[i] == ';' || str[i] == ' ') {
            str2[a] = '&';
            while (str[i] == ';' || str[i] == ' ') {
                i++;
            }
            i -= 1;
            a += 1;
        }
    }
    str2[a] = '\0';
    str2 = clear_mystr(str2);
    str2 = unparse_pv(str2);
    return (str2);
}

char *clear_arr(char *str)
{
    if (is_err(str)) {
        return (str);
    }
    if (is_pv(str)) {
        str = parse_clear_arr(str);
    }
    return (str);
}
