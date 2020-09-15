/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** history_file
*/

#include "history.h"

list_t *history_retrieve_from_file(void)
{
    list_t *history = NULL;
    char *retrieved = NULL;
    FILE *f = fopen(HISTORY_FILEPATH, "r");
    ssize_t eof = 0;
    size_t n = 0;

    if (f == NULL)
        return (NULL);
    do {
        retrieved = NULL;
        eof = getline(&retrieved, &n, f);
        if (eof == -1 || !retrieved)
            break;
        retrieved[eof - 1] = '\0';
        list_insert(&history, strdup(retrieved));
    } while (retrieved != NULL);
    fclose(f);
    return history;
}

void history_save(list_t *history)
{
    int fd = open(HISTORY_FILEPATH, O_CREAT | O_WRONLY, 0664);

    if (fd == -1) {
        dprintf(2, "Failed open while saving history");
        return;
    }
    for (list_t *curr = history; curr; curr = curr->next) {
        write(fd, (char *)curr->data, strlen((char *)curr->data));
        write(fd, "\n", 1);
    }
    list_free(&history, NULL);
}