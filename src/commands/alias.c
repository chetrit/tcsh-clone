/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** alias
*/

#include "commands/alias.h"

int alias_exists(shell_t *shell, char **av)
{
    shell_alias_t *tmp = shell->alias;

    while (tmp) {
        if (strcmp(tmp->command, av[1]) == 0) {
            tmp->alias = &av[2];
            return (1);
        }
        tmp = tmp->next;
    }
    return (0);
}

int alias_check_particular_cases(shell_t *shell, char **av)
{
    int fd = FD_TO_WRITE(shell->redirect.fd_out);

    if (!av[1]) {
        print_all_alias(shell, fd);
        return (1);
    }
    if (!av[2]) {
        print_one_alias(shell, av[1]);
        return (1);
    }
    if (alias_exists(shell, av)) {
        return (1);
    }
    return (0);
}

void create_alias(shell_t *shell, char **av)
{
    shell_alias_t *head = shell->alias;

    if (alias_check_particular_cases(shell, av)) {
        return;
    }
    if (!shell->alias) {
        shell->alias = malloc(sizeof(shell_alias_t));
        shell->alias->command = strdup(av[1]);
        shell->alias->alias = &av[2];
        shell->alias->next = NULL;
    } else {
        while (shell->alias->next) {
            shell->alias = shell->alias->next;
        }
        shell->alias->next = malloc(sizeof(shell_alias_t));
        shell->alias->next->command = strdup(av[1]);
        shell->alias->next->alias = &av[2];
        shell->alias->next->next = NULL;
        shell->alias = head;
    }
}

char **insert_alias(char **av, char **alias)
{
    int i = 0;
    int j = 1;

    for (; alias[i] != NULL; ++i);
    for (; av[j] != NULL; ++j, ++i) {
        alias[i] = av[j];
    }
    alias[i] = NULL;
    return (alias);
}

char **replace_alias(shell_t *shell, char **av)
{
    shell_alias_t *head = shell->alias;

    if (!shell->alias) {
        return (av);
    }
    if (shell->alias && strcmp(shell->alias->command, av[0]) == 0) {
        return (insert_alias(av, shell->alias->alias));
    }
    while (shell->alias->next) {
        if (strcmp(shell->alias->next->command, av[0]) == 0) {
            av = insert_alias(av, shell->alias->next->alias);
            shell->alias = head;
            return (av);
        }
        shell->alias = shell->alias->next;
    }
    shell->alias = head;
    return (av);
}
