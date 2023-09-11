SRCS = ft_printf.c ft_printf_put.c


OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

CC = gcc

LIBAR = ar rc

LIBRAN = ranlib

RM = rm -f

CD = cd

MAKE = make

CFLAGS = -Wall -Wextra -Werror

%o:%c ft_printf.h
	${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
	${LIBAR} ${NAME} ${OBJS}
	${LIBRAN} ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY:all fclean clean re