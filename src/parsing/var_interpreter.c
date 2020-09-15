/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** var interpreter parser
*/

#include "parsing/var_interpreter.h"

char *get_var(char *str)
{
    char *final = malloc(sizeof(char) * (strlen(str) + 1));
    int i = 0;

    for (; str[i] != ' ' && str[i] != '\t' && str[i] != '\0'; ++i) {
        final[i] = str[i];
    }
    final[i] = '\0';
    return (final);
}

int var_interpreter_get_size(char **env, char *str)
{
    int size = 1;
    char *var = NULL;
    char *tmp = NULL;

    if (nb_sc(str, '$') == 0)
        return (0);
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '$') {
            if (str[i++] + 1 == ' ' || str[i] == '\t' || str[i] == '\0')
                return (0);
            var = get_var(&str[i]);
            tmp = get_env(env, var);
            if (!tmp)
                return (0);
            size += strlen(tmp) + 1;
            i += strlen(var);
        }
        size = str[i] == '$' ? size : size + 1;
    }
    return (size);
}

int var_interpreter_copy_var(int *j, char **final, char *tmp, char *var)
{
    if (!tmp) {
        if (var[strlen(var) - 1] == '"')
            var[strlen(var) - 1] = '\0';
        dprintf(2, "%s: Undefined variable.\n", var);
        return (1);
    }
    for (int k = 0; tmp[k] != '\0'; ++k)
        (*final)[(*j)++] = tmp[k];
    (*final)[(*j)++] = ' ';
    return (0);
}

int var_interpreter_error(char *str, int *i)
{
    if (str[(*i)++] + 1 == ' ' || str[*i] == '\t'
        || str[*i] == '\0' || str[*i] == '\"') {
        dprintf(2, "Illegal variable name.\n");
        return (1);
    }
    return (0);
}

char *parse_var_interpreter(char **env, char *str)
{
    char *final = malloc(sizeof(char) * var_interpreter_get_size(env, str));
    char *tmp = NULL;
    char *var = NULL;
    int j = 0;

    if (nb_sc(str, '$') == 0)
        return (str);
    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] == '$') {
            if (var_interpreter_error(str, &i))
                return (NULL);
            var = get_var(&str[i]);
            tmp = get_env(env, var);
            if (var_interpreter_copy_var(&j, &final, tmp, var))
                return (NULL);
            i += strlen(var);
        } else
            final[j++] = str[i];
    final[j] = '\0';
    return (final);
}