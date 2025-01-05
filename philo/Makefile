NAME = philo
SRC = main.c parse.c ft_atoi.c
SRC_OBJS = ${SRC:.c=.o}
CC = cc
CFLAGS = 
# -Wall -Werror -Wextra

${NAME}: ${SRC_OBJS}
	${CC} ${CFLAGS} ${SRC_OBJS} -o ${NAME}

%.o: %.c philo.h
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

clean:
	rm -f ${SRC_OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
