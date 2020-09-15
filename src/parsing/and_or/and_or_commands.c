/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** and or commands
*/

#include "parsing/and_or/and_or_commands.h"

char **andor_get_first_command(char **av)
{
    char **tmp_av = NULL;
    int i = 0;

    for (i = 0; av[i] && strcmp(av[i], "||") != 0
        && strcmp(av[i], "&&") != 0; i++);
    tmp_av = malloc(sizeof(char *) * (i + 1));
    for (i = 0; av[i] && strcmp(av[i], "||") != 0
        && strcmp(av[i], "&&") != 0; i++)
        tmp_av[i] = strdup(av[i]);
    tmp_av[i] = NULL;
    return (tmp_av);
}

char **andor_get_last_command(char **av)
{
    char **last = NULL;
    int j = 0;
    int stock = 0;
    int nb = 0;

    for (int i = 0; av[i]; i++) {
        j = strcmp(av[i], "||") == 0 || strcmp(av[i], "&&") == 0 ? i : j;
    }
    stock = j;
    for (; av[j]; j++, nb++);
    last = malloc(sizeof(char *) * (nb + 1));
    nb = stock;
    for (j = 0, ++stock; av[stock]; stock++, j++) {
        last[j] = strdup(av[stock]);
    }
    last[j] = NULL;
    av[nb] = NULL;
    return (last);
}

int andor_get_nb_after_pipe(char **av)
{
    int i = 0;

    for (; av[i] && strcmp(av[i], "||") != 0 && strcmp(av[i], "&&") != 0; i++);
    return (i + 1);
}

char **andor_get_next_command(char **av)
{
    char **tmp_av = NULL;
    int i = 0;
    int j = 0;

    for (i = 0; av[i] && strcmp(av[i], "||") != 0
        && strcmp(av[i], "&&") != 0; i++);
    if (!av[i]) {
        return (NULL);
    }
    tmp_av = malloc(sizeof(char *) * (andor_get_nb_after_pipe(&av[++i])));
    for (j = 0; av[i] && strcmp(av[i], "||") != 0
        && strcmp(av[i], "&&") != 0; i++, j++) {
        tmp_av[j] = strdup(av[i]);
    }
    tmp_av[j] = NULL;
    return (tmp_av);
}

char ***get_and_or_commands(char **av, int nb_gates)
{
    char ***avs = malloc(sizeof(char **) * (nb_gates + 2));
    int i = 1;

    avs[0] = andor_get_first_command(av);
    for (; i < nb_gates; i++) {
        avs[i] = andor_get_next_command(av);
        av += andor_get_nb_after_pipe(av);
    }
    avs[i] = andor_get_last_command(av);
    avs[i + 1] = NULL;
    return (avs);
}