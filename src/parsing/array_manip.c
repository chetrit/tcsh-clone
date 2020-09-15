/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** 2d array minipulation function
*/

#include "parsing/array_manip.h"

bool is_empty_arr(char **arr)
{
    if (!arr || !arr[0] || arr[0][0] == ';') {
        return (true);
    }
    for (int i = 0; arr[i] != NULL; ++i) {
        if (is_alphanum(arr[i][0]) || is_alphanum(arr[i][1])
            || arr[i][0] == '!') {
            return (false);
        }
    }
    printf("%s: Command not found.\n", arr[0]);
    return (true);
}

int create_single_arr(shell_t *shell, int nb_semicolons)
{
    if (nb_semicolons == 0 || shell->cmds.arr[0][0] == ';') {
        shell->cmds.avs = malloc(sizeof(char **) * 2);
        shell->cmds.avs[0] = shell->cmds.arr;
        shell->cmds.avs[1] = NULL;
        return (1);
    } else {
        return (0);
    }
}

void create_arrays_extend(shell_t *shell, int *i, int *j)
{
    if (shell->cmds.arr[0][0] == ';' && shell->cmds.arr[0][1] == '\0') {
            *j += 1;
            *i = 0;
            shell->cmds.arr += 1;
        }
    if (is_semicolon(shell->cmds.arr[0])) {
        shell->cmds.avs[*j][*i] = shell->cmds.arr[0];
        *j += 1;
        *i = 0;
        shell->cmds.arr += 1;
    }
    shell->cmds.avs[*j][(*i)++] = shell->cmds.arr[0];
    shell->cmds.avs[*j][*i] = NULL;
}

void create_arrays(shell_t *shell)
{
    int nb_semiconlons = get_nb_semicolons(shell);
    int i = 0;
    int j = 0;

    if (create_single_arr(shell, nb_semiconlons))
        return;
    shell->cmds.avs = malloc(sizeof(char **) * (nb_semiconlons + 2));
    for (; shell->cmds.arr[i]; i++);
    for (j = 0; j < nb_semiconlons + 1; j++) {
        shell->cmds.avs[j] = malloc(sizeof(char *) * (i + 1));
    }
    for (i = 0, j = 0; shell->cmds.arr[0]; shell->cmds.arr++) {
        create_arrays_extend(shell, &i, &j);
    }
    shell->cmds.avs[j + 1] = NULL;
    remove_semicolons(shell);
}

void format_arr(shell_t *shell)
{
    char **final = NULL;
    int i = 0;
    int j = 0;

    for (; shell->cmds.arr[i]; i++);
    final = malloc(sizeof(char *) * (i + 1));
    for (i = 0, j = 0; shell->cmds.arr[i]; i++) {
        if (!only_space_and_tabs(shell->cmds.arr[i])) {
            final[j] = my_strdup(shell->cmds.arr[i]);
            j += 1;
            final[j] = NULL;
        }
    }
    for (i = 0; final[i]; i++) {
        if (final[i][0] == ' ' || final[i][0] == '\t') {
            final[i] = &final[i][1];
        }
    }
    shell->cmds.arr = final;
}