/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** double quot file
*/

#include "parsing/input/double_quote.h"

char *double_quote(char *separators, char **arr, int i)
{
    char *str = NULL;

    str = malloc(sizeof(char) * (strlen(arr[i])));
    str = cpy_dquote(str, arr[i]);
    str = re_modify_str(str, separators);
    if (arr[index_darr(arr)][strlen(arr[index_darr(arr)]) - 1] == '"')
        arr[index_darr(arr)][strlen(arr[index_darr(arr)]) - 1] = '\0';
    arr[i] = strcpy(arr[i], str);
    return (arr[i]);
}