/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** where command
*/

#include "commands/where.h"

void where_alias(shell_t *shell, char *str, int fd)
{
    shell_alias_t *tmp = shell->alias;

    while (tmp) {
        if (strcmp(tmp->command, str) == 0) {
            dprintf(fd, "%s is aliased to ", str);
            alias_print_2d_array(tmp->alias);
            return;
        }
        tmp = tmp->next;
    }
}

int where_built_ins(char *str, int fd)
{
    for (int i = 0; i < NB_COMMANDS; ++i) {
        if (strcmp(commands[i].command, str) == 0) {
            dprintf(fd, "%s is a shell built-in\n", str);
            return (1);
        }
    }
    return (0);
}

void where_paths(shell_t *shell, char *str, int fd)
{
    char **arr = one_dim_to_two_dim(get_env(shell->env, "PATH"), ':');

    for (int i  = 0; arr[i] != NULL; i++) {
        if (arr[i][strlen(arr[i]) - 1] != '/') {
            arr[i] = my_strcat(arr[i], "/");
        }
        if (access(my_strcat(arr[i], str), X_OK) == 0) {
            dprintf(fd, "%s\n", my_strcat(arr[i], str));
        }
    }
}

void where(shell_t *shell, char **av)
{
    int fd = FD_TO_WRITE(shell->redirect.fd_out);

    for (int i = 1; av[i] != NULL; i++) {
        where_alias(shell, av[i], fd);
        where_built_ins(av[i], fd);
        where_paths(shell, av[i], fd);
    }
}