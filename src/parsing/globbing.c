/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** globbing
*/

#include "parsing/globbing.h"

static bool is_chr_in_str(char const *s, const char c)
{
    if (s == NULL)
        return false;
    for (int i = 0; s[i]; i++)
        if (s[i] == c)
            return true;
    return false;
}

static size_t tab_len(char **tab)
{
    size_t size = 0;

    for (; tab && tab[size]; size++);
    return size;
}

static char **generate_non_glob_array(char **tab, char *to_add)
{
    size_t len = tab_len(tab);
    char **new = malloc(sizeof(char *) * (len + 2));

    if (!new) {
        dprintf(2, "Malloc failed.\n");
        exit(84);
    }
    for (size_t i = 0; i != len; i++) {
        new[i] = strdup(tab[i]);
        if (!new[i]) {
            dprintf(2, "Malloc failed.\n");
            exit(84);
        }
    }
    new[len] = to_add;
    new[len + 1] = NULL;
    return new;
}

static char **concat_glob_to_array(char **tab, wordexp_t exp)
{
    size_t len = tab_len(tab);
    size_t i = 0;
    char **new = malloc(sizeof(char *) * (len + exp.we_wordc + 1));

    if (!new) {
        dprintf(2, "Malloc failed.\n");
        exit(84);
    }
    for (; i != len; i++) {
        new[i] = strdup(tab[i]);
        if (!new[i]) {
            dprintf(2, "Malloc failed.\n");
            exit(84);
        }
    }
    for (size_t j = 0; j < exp.we_wordc; j++) {
        new[i + j] = strdup(exp.we_wordv[j]);
    }
    new[len + exp.we_wordc] = NULL;
    return new;
}

char **globbing(char **av)
{
    char **tab = NULL;
    wordexp_t exp = {0};

    for (int i = 0; av && av[i]; i++) {
        if (!is_chr_in_str(av[i], '*') && !is_chr_in_str(av[i], '[')
        && !is_chr_in_str(av[i], '?') && !is_chr_in_str(av[i], '{')) {
            tab = generate_non_glob_array(tab, av[i]);
            continue;
        }
        wordexp(av[i], &exp, WRDE_NOCMD);
        if (!exp.we_wordv)
            return av;
        tab = concat_glob_to_array(tab, exp);
        wordfree(&exp);
    }
    return tab;
}