/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** alias command utils
*/

#include "commands/alias_utils.h"

void alias_print_2d_array(char **arr, int fd)
{
    int i = 0;

    for (; arr[i + 1] != NULL; i++)
        dprintf(fd, "%s ", arr[i]);
    dprintf(fd, "%s\n", arr[i]);
}

void print_all_alias(shell_t *shell, int fd)
{
    shell_alias_t *tmp = shell->alias;

    while (tmp) {
        dprintf(fd, "%s ", tmp->command);
        alias_print_2d_array(tmp->alias, fd);
        tmp = tmp->next;
    }
}

void print_one_alias(shell_t *shell, char *alias)
{
    shell_alias_t *tmp = shell->alias;
    int fd = FD_TO_WRITE(shell->redirect.fd_out);

    while (tmp) {
        if (strcmp(tmp->command, alias) == 0) {
            return (alias_print_2d_array(tmp->alias, fd));
        }
        tmp = tmp->next;
    }
}