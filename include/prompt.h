/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** prompt header
*/

#ifndef PROMPT_H_
#define PROMPT_H_

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
#include "my_utils.h"

char *get_env(char **envp, char *str);

#endif /* PROMPT_H_ */
