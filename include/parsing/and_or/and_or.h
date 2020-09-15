/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** and or commands header
*/

#ifndef AND_OR_H_
#define AND_OR_H_

#include <stdlib.h>
#include <string.h>

#include "structures.h"
#include "global.h"

char ***get_and_or_commands(char **av, int nb_gates);
void check_commands(shell_t *shell, char **av);

#endif /* !AND_OR_H_ */
