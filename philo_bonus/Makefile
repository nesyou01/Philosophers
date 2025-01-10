NAME = philo_bonus
SRC = main_bonus.c ft_atoi_bonus.c init_bonus.c utils_bonus.c philo_bonus.c
SRC_OBJS = ${SRC:.c=.o}
CC = cc
CFLAGS = 
# -Wall -Werror -Wextra

${NAME}: ${SRC_OBJS}
	${CC} ${CFLAGS} ${SRC_OBJS} -o ${NAME}

%.o: %.c philo_bonus.h
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

clean:
	rm -f ${SRC_OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
