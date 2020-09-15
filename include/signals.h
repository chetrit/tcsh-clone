/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** signals header
*/

#ifndef SIGNALS_H_
#define SIGNALS_H_

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
#include "global.h"
#include "node.h"

typedef enum job_type_s
{
    CTRLZ,
    AND,
    DONE,
    UNDEFINED
} job_type_t;

typedef struct job_s
{
    pid_t pid;
    job_type_t type;
    char *cmd;
} job_t;

extern list_t *JOBS;

void handle_chld(int sig, siginfo_t *info, void *context);
void handle_signal_shell(_Bool is_shell);
bool filter_func(job_t *job);

#endif /* !SIGNALS_H_ */
