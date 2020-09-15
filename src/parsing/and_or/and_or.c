/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** and or commands
*/

#include "parsing/and_or/and_or.h"

bool *and_or_init(char **av, int *nb_gates)
{
    bool *gates = NULL;
    int j = 0;

    for (int i = 0; av[i] != NULL; ++i) {
        if (strcmp(av[i], "||") == 0 || strcmp(av[i], "&&") == 0) {
            (*nb_gates)++;
        }
    }
    if (*nb_gates == 0)
        return (NULL);
    gates = malloc(sizeof(int) * (*nb_gates + 1));
    for (int i = 0; av[i] != NULL; ++i) {
        if (strcmp(av[i], "||") == 0) {
            gates[j++] = 0;
        } else if (strcmp(av[i], "&&") == 0) {
            gates[j++] = 1;
        }
    }
    return (gates);
}

int check_for_and_or(shell_t *shell, char **av)
{
    int nb_gates = 0;
    bool *gates = and_or_init(av, &nb_gates);
    int i = 0;

    if (!gates) {
        return (0);
    }
    shell->cmds.and_or_avs = get_and_or_commands(av, nb_gates);
    for (; i < nb_gates + 1; ++i) {
        check_commands(shell, shell->cmds.and_or_avs[i]);
        if ((shell->utils.return_value > 0 && gates[i] == 0)
            || (shell->utils.return_value == 0 && gates[i] == 1)) {
            shell->utils.return_value = 0;
            continue;
        }
        break;
    }
    return (1);
}