/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** redirections header
*/

#ifndef REDIRECTIONS_H_
#define REDIRECTIONS_H_

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#include "structures.h"
#include "my_utils.h"

void print_error(char *name, int err, bool more, bool even_more);

#endif /* REDIRECTIONS_H_ */
