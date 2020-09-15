/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** parse_inhibitors
*/

#ifndef PARSE_INHIBITORS_H_
#define PARSE_INHIBITORS_H_

#include <stdlib.h>
#include <string.h>

struct escape_sequences_s
{
    char lettter;
    char c;
};

static const struct escape_sequences_s ESCAPE_SEQUENCES[9] =
{
    {'0', '\0'},
    {'a', '\a'},
    {'b', '\b'},
    {'t', '\t'},
    {'n', '\n'},
    {'v', '\v'},
    {'f', '\f'},
    {'r', '\r'},
    {'\\', '\\'}
};

#endif /* !PARSE_INHIBITORS_H_ */