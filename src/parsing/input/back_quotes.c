/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** back quotes
*/

#include "parsing/input/back_quotes.h"

char *remove_spaces(char *str)
{
    char *final = malloc(sizeof(char) * (strlen(str) + 1));
    int i = 0;
    int j = 0;

    for (; str[i] != '\0'; ++i) {
        if (str[i] == ' ') {
            final[j++] = ' ';
            for (; str[i + 1] == ' ' && str[i + 1] != '\0'; ++i);
        } else {
            final[j++] = str[i];
        }
    }
    final[j] = '\0';
    return (final);
}

char *back_quote_read_str(int fd, int size)
{
    char final[size];

    if (size == 0)
        return (" ");
    pread(fd, &final, size, 0);
    final[size] = '\0';
    close(fd);
    for (int i = 0; final[i] != '\0'; ++i) {
        if (final[i] == '\n' || final[i] == '\t') {
            final[i] = ' ';
        }
    }
    if (final[strlen(final) - 1] == ' ') {
        final[strlen(final) - 1] = '\0';
    }
    return (remove_spaces(strdup(final)));
}

char *exec_command_back_quote(char *str, char **env)
{
    shell_t shell;
    int tmp_fd = open("/tmp", __O_TMPFILE | O_RDWR, S_IRUSR | S_IWUSR);
    int save_out = dup(STDOUT_FILENO);
    int save_err = dup(STDERR_FILENO);
    struct stat sb;

    init_shell(&shell, env);
    shell.utils.input = str;
    dup2(tmp_fd, STDOUT_FILENO);
    dup2(tmp_fd, STDERR_FILENO);
    loop_shell(&shell);
    dup2(save_out, STDOUT_FILENO);
    dup2(save_err, STDERR_FILENO);
    close(save_out);
    close(save_err);
    fstat(tmp_fd, &sb);
    return (back_quote_read_str(tmp_fd, sb.st_size));
}