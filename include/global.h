/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** global header
*/

#ifndef GLOBAL_H_
#define GLOBAL_H_

#define UNUSED __attribute__((unused))
#define FD_TO_WRITE(fd) fd == -1 || fd == -2 ? 1 : fd;

static const int ERROR = 84;

#endif /* GLOBAL_H_ */
