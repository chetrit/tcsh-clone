/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** foreground command
*/

#include "commands/fg.h"
#include "global.h"
#include "signals.h"

static job_t *get_index_of_list(list_t *list, int index)
{
    int i = 0;

    for (list_t *tmp = list; tmp; tmp = tmp->next) {
        if (index == i)
            return (tmp->data);
        i += 1;
    }
    return (NULL);
}

void fg(shell_t *shell, char **av)
{
    int index = 0;
    int fd = FD_TO_WRITE(shell->redirect.fd_out);
    job_t *old_cmd = NULL;

    if (!JOBS) {
        dprintf(2, "fg: No current job.\n");
        shell->utils.exit = 1;
        return;
    }
    if (av[1]) {
        index = atoi(av[1]);
    }
    old_cmd = get_index_of_list(JOBS, index);
    if (!old_cmd) {
        old_cmd = get_index_of_list(JOBS, 0);
    }
    dprintf(fd, "%s\n", old_cmd->cmd);
    kill(old_cmd->pid, SIGCONT);
}
