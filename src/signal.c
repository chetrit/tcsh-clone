/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** handle signals
*/

#include "signals.h"

list_t *JOBS;

void insert_new_job(char *cmd)
{
    job_t *new = malloc(sizeof(job_t));

    if (!new)
        return;
    new->cmd = cmd;
    new->pid = -1;
    new->type = UNDEFINED;
    list_insert(&JOBS, new);
}

bool filter_func(job_t *job)
{
    if (job->type == UNDEFINED || job->pid == -1) {
        return (false);
    }
    return (true);
}

void free_job(job_t *job)
{
    free(job);
}

void handle_chld(UNUSED int sig, siginfo_t *info, UNUSED void *context)
{
    job_t *curr;

    if (info->si_code == CLD_STOPPED) {
        printf("\nSuspended\n");
        if (!JOBS || !JOBS->data)
            return;
        curr = JOBS->data;
        curr->pid = info->si_pid;
        curr->type = CTRLZ;
    } else {
        list_filter(&JOBS, filter_func, free_job);
    }
    return;
}

void handle_signal_shell(_Bool is_shell)
{
    struct sigaction sigbuf = {0};

    if (is_shell) {
        sigbuf.sa_flags = SA_SIGINFO;
        sigbuf.sa_sigaction = handle_chld;
        signal(SIGINT, SIG_IGN);
        signal(SIGTSTP, SIG_IGN);
        sigaction(SIGCHLD, &sigbuf, NULL);
    } else {
        signal(SIGTSTP, SIG_DFL);
        signal(SIGINT, SIG_DFL);
    }
}