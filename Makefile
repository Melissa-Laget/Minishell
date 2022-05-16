##
## EPITECH PROJECT, 2022
## sokoban [WSL: Manjaro]
## File description:
## Makefile
##

override CFLAGS += -fno-builtin -W -Wall -Wextra -Wno-ignored-qualifiers
override CPPFLAGS += -I./include

SRC	=	src/command/cd_command.c	\
		src/command/printf_env.c	\
		src/command/get_error.c		\
		src/command/unsetenv.c		\
		src/command/get_file.c		\
		src/command/setenv.c		\
		src/command/env.c		\
		src/command/cd.c		\
		src/minishell.c			\
		src/get_input.c			\
		src/free_all.c			\
		src/get_cmd.c			\
		src/init.c			\
		src/list.c

OBJ	=	$(SRC:.c=.o)

MAINSRC	=	main.c

MAINOBJ	=	$(MAINSRC:.c=.o)

NAME	=	mysh

LDFLAGS		= 	-L./lib/

LDLIBS		=	-lmy -lprintf -lprinterr

all:	$(NAME)

lib:
	make -C ./lib/my
	make -C ./lib/printf
	make -C ./lib/printerr

$(NAME):	lib $(OBJ) $(MAINOBJ)
	gcc $(CPPFLAGS) -o $(NAME) $(MAINOBJ) $(OBJ) $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(OBJ) $(MAINOBJ)
	make -C ./lib/my clean
	make -C ./lib/printf clean
	make -C ./lib/printerr clean

fclean: clean
	rm -f $(NAME)
	make -C ./lib/my fclean
	make -C ./lib/printf fclean
	make -C ./lib/printerr fclean

re:	fclean all

debug:	CFLAGS += -g
debug:	re

.PHONY: all lib clean fclean re debug
