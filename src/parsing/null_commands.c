/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** null command parser
*/

#include "parsing/null_commands.h"

int is_null_command(char *str)
{
    int counter = 0;
    int i = 0;

    for (; str[i] != '|'; i++) {
        if (str[i] != ';' && str[i] != '|' && str[i] != ' ' && str[i] != '\t') {
            counter++;
        }
    }
    if (counter == 0) {
        return (1);
    }
    for (counter = 0; str[i] != '\0' && str[i] != ';'; i++) {
        if (str[i] == '(')
            return (1);
        if (str[i] != ';' && str[i] != '|' && str[i] != ' ' && str[i] != '\t') {
            return (0);
        }
    }
    return (1);
}

int is_mult_pipes_extend(char *str, int *i)
{
    int j = 0;

    if (str[*i] == '|') {
        for (; str[*i] == '|'; ++(*i), ++j);
        if (j > 2)
            return (1);
    }
    return (0);
}

int is_mult_pipes(char *str)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        if (is_mult_pipes_extend(str, &i))
            return (1);
    }
    return (0);
}

int parse_null_command(shell_t *shell, char *str)
{
    if (nb_sc(str, '|') > 0 && (is_null_command(str) || is_mult_pipes(str))) {
        my_put_error("Invalid null command.\n");
        shell->utils.return_value = 1;
        return (1);
    }
    return (0);
}