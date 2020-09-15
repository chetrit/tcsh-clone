/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** pipes parser
*/

#include "parsing/parse_pipes.h"

int get_nb_pipes(char *str)
{
    int counter = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '|' && (str[i + 1] != '|' && str[i - 1] != '|')) {
            counter += 1;
        }
    }
    return (counter);
}

char *parse_pipes(char *str)
{
    char *newstr = malloc(sizeof(char) * (strlen(str) + get_nb_pipes(str) * 3));
    int j = 0;

    if (get_nb_pipes(str) == 0) {
        return (str);
    }
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '|' && (str[i + 1] != '|' && str[i - 1] != '|')) {
            newstr[j++] = ' ';
            newstr[j++] = '|';
            newstr[j++] = ' ';
        } else {
            newstr[j++] = str[i];
        }
    }
    newstr[j] = '\0';
    return (newstr);
}