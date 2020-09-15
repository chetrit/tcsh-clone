/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** which command
*/

#include "commands/which.h"

int which_alias(shell_t *shell, char *str, int fd)
{
    shell_alias_t *tmp = shell->alias;

    while (tmp) {
        if (strcmp(tmp->command, str) == 0) {
            dprintf(fd, "%s: \t aliased to ", str);
            alias_print_2d_array(tmp->alias);
            return (1);
        }
        tmp = tmp->next;
    }
    return (0);
}

int which_built_ins(char *str, int fd)
{
    for (int i = 0; i < NB_COMMANDS; ++i) {
        if (strcmp(commands[i].command, str) == 0) {
            dprintf(fd, "%s: shell built-in command.\n", str);
            return (1);
        }
    }
    return (0);
}

int which_path(shell_t *shell, char *str, int fd)
{
    char **path_arr = one_dim_to_two_dim(get_env(shell->env, "PATH"), ':');
    char *path = NULL;

    for (int i = 0; path_arr[i] != NULL; i++) {
        path = malloc(sizeof(char) *
            (strlen(path_arr[i]) + strlen(str + 1)));
        path = path_arr[i];
        path = path_arr[i][strlen(path_arr[i]) - 1] == '/' ?
            my_strcat(path, str) : my_strcat(my_strcat(path, "/"), str);
        if (access(path, X_OK) != -1) {
            dprintf(fd, "%s\n", path);
            return (1);
        }
    }
    dprintf(2, "%s: Command not found.\n", str);
    return (0);
}

void which(shell_t *shell, char **av)
{
    int fd = FD_TO_WRITE(shell->redirect.fd_out);

    for (int i = 1; av[i] != NULL; ++i) {
        if (which_built_ins(av[i], fd)) {
            continue;
        } else if (which_alias(shell, av[i], fd)) {
            continue;
        } else {
            which_path(shell, av[i], fd);
        }
    }
}
