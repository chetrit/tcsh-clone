##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## minishell2 Makefile
##

CC	?=	gcc

SRC =	src/commands/cd.c				\
	src/commands/setenv.c				\
	src/commands/unsetenv.c				\
	src/commands/exit.c				\
	src/commands/alias.c				\
	src/commands/alias_utils.c			\
	src/commands/repeat.c				\
	src/commands/where.c				\
	src/commands/which.c				\
	src/commands/fg.c				\
	src/commands/jobs.c				\
	src/commands/echo.c			\
							\
	src/my_utils/my_atoi.c				\
	src/my_utils/my_put_error.c			\
	src/my_utils/my_putstr.c			\
	src/my_utils/my_strcat.c			\
	src/my_utils/my_strcmp.c			\
	src/my_utils/my_strcpy.c			\
	src/my_utils/my_strdup.c			\
	src/my_utils/my_strlen.c			\
	src/my_utils/my_strncmp.c			\
	src/my_utils/my_strncpy.c			\
	src/my_utils/one_dim_to_two_dim.c		\
							\
	src/parsing/array_manip.c			\
	src/parsing/close_redirections.c		\
	src/parsing/redirections.c			\
	src/parsing/semicolons_utils.c			\
	src/parsing/special_char.c			\
	src/parsing/null_commands.c			\
	src/parsing/parse_pipes.c			\
	src/parsing/parse_inhibitors.c			\
	src/parsing/parse_redirects.c			\
	src/parsing/var_interpreter.c			\
	src/parsing/globbing.c				\
							\
	src/parsing/input/parse_input.c		\
	src/parsing/input/parse_tools.c		\
	src/parsing/input/quotes_tools.c		\
	src/parsing/input/back_quotes.c			\
	src/parsing/input/clear_arr.c 			\
	src/parsing/input/clear_parse_tools.c   \
	src/parsing/input/is_to_clear.c         \
	src/parsing/input/parenthesis.c   		\
	src/parsing/input/double_quote.c 		\
							\
	src/parsing/pipes/pipe_redirections.c		\
	src/parsing/pipes/pipes_utils.c			\
	src/parsing/pipes/pipes.c			\
	src/parsing/pipes/single_pipe_redirection.c	\
							\
	src/parsing/and_or/and_or.c			\
	src/parsing/and_or/and_or_commands.c 		\
							\
	src/init_shell.c				\
	src/env.c					\
	src/execute.c					\
	src/main.c					\
	src/minishell.c					\
	src/print_error.c				\
	src/prompt.c					\
	src/signal.c					\
	src/node.c					\
	src/get_input.c				\
	src/history.c					\
	src/history_file.c				\

OBJ	=	$(SRC:.c=.o)

NAME = 42sh

CFLAGS	+= -W -Wall

CPPFLAGS	+=	-I include/

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

bonus:
	$(CC) -o line_editing_example src/line_editing/line_editing.c src/line_editing/set_term.c -I include/ -lncurses

debug: CFLAGS += -g3
debug: $(NAME)

clean:
	rm -f src/line_editing/*.o
	rm -f $(OBJ)

fclean:	clean
	rm -f line_editing_example
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
