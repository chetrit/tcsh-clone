/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** parse_tools
*/

#include "parsing/input/parse_tools.h"

int index_darr(char **str)
{
    int index = 0;

    for (; str[index] != NULL; index++);
    index -= 1;
    return (index);
}

char *modify_str(char *str, int i, char *separators)
{
    i++;
    for (; str[i] != '`' && str[i] != 34 && str[i] != '('
    && str[i] != ')' && str[i] != '\0'; i++) {
        if (str[i + 1] == '`') {
            return (str);
        }
        for (int j = 0; separators[j] != '\0'; j++) {
            if (str[i] == separators[j]) {
                str[i] = j + 48;
            }
        }
    }
    return (str);
}

char *parse_str(char *separators, char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] == '`' || str[i] == 34 || str[i] == '(' || str[i] == ')')
        && (is_two_quote(str, i) == 1)) {
            str = modify_str(str, i, separators);
        }
    }
    return (str);
}

char *re_modify_str(char *str, char *separators)
{
    for (int i = 0, j = 0; str[i] != '\0'; i++) {
        for (j = 0; separators[j] != '\0'; j++) {
            if (str[i] == j + 48) {
                str[i] = separators[j];
            }
        }
    }
    return (str);
}

char **unparse_dstr(char **arr, char *separators, char **env)
{
    char *command = NULL;

    for (int i = 0; arr[i] != NULL; i++) {
        if (arr[i][0] == '`') {
            command = keep_backquotes(arr[i]);
            command = re_modify_str(command, separators);
            arr[i] = exec_command_back_quote(command, env);
        }
        if (arr[i][0] == '(') {
            command = keep_backquotes(arr[i]);
            command = re_modify_str(command, separators);
            exec_command_parenthesis(command, env);
            arr[i] = NULL;
        } else if (arr[i][0] == '"') {
            arr[i] = double_quote(separators, arr, i);
            return (arr);
        }
    } return (arr);
}