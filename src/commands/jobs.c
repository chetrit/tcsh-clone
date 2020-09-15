/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** jobs builtin
*/

#include "commands/jobs.h"
#include "signals.h"
#include "global.h"

void jobs(UNUSED shell_t *shell, UNUSED char **av)
{
    char buf[33] = {0};
    job_t *job = NULL;
    unsigned int i = 1;
    int fd = FD_TO_WRITE(shell->redirect.fd_out);

    for (list_t *curr = JOBS; curr; curr = curr->next) {
        job = curr->data;
        for (size_t j = 0; j != strlen(JOBS_MESSAGE[job->type]); j++)
            buf[j] = JOBS_MESSAGE[job->type][j];
        for (int j = strlen(JOBS_MESSAGE[job->type]) + 1; j < 32; j++)
            buf[j] = ' ';
        dprintf(fd, "[%d]  %s%s\n", i, buf, job->cmd);
        i++;
    }
}
