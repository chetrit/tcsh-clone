/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** redirections parser
*/

#include "parsing/parse_redirects.h"

int is_invalid_redirect(char *str)
{
    int counter = 0;
    int i = 0;

    for (; str[i] != '<' && str[i] != '>'; i++) {
        if (is_alphanum(str[i])) {
            counter++;
        }
    }
    if (counter == 0) {
        dprintf(2, "Invalid null command.\n");
        return (1);
    }
    for (++i; str[i] == '>' && str[i] == '<'; ++i);
    for (counter = 0; str[i] != '\0'; i++) {
        if (is_alphanum(str[i])) {
            return (0);
        }
    }
    dprintf(2, "Missing name for redirect.\n");
    return (1);
}

int nb_redirections(char *str)
{
    int counter = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        if ((str[i] == '<' && str[i + 1] == '<')
            || (str[i] == '>' && str[i + 1] == '>')) {
            i += 1;
            counter += 1;
        }
        else if (str[i] == '<' || str[i] == '>') {
            counter += 1;
        }
    }
    return (counter);
}

int is_mult_redirect_extend(char *str, int *i)
{
    int j = 0;

    if (str[*i] == '>' || str[*i] == '<') {
        for (; str[*i] == '>' || str[*i] == '<'; ++(*i), ++j);
        if (j > 2)
            return (1);
    }
    return (0);
}

int is_mult_redirect(char *str)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        if (is_mult_redirect_extend(str, &i)) {
            dprintf(2, "Missing name for redirect.\n");
            return (1);
        }
    }
    return (0);
}

int parse_invalid_redirects(shell_t *shell, char *str)
{
    if (nb_redirections(str) > 0
        && (is_invalid_redirect(str) || is_mult_redirect(str))) {
        shell->utils.return_value = 1;
        return (1);
    }
    return (0);
}