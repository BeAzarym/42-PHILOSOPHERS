NAME	=	philo

SRC =	main.c \
		parser.c \
		libft_utils.c \
		error.c \

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))

OBJS = $(SRCS:.c=.o)

SRC_DIR = src
INC_DIR = include

CFLAGS = -Wall -Wextra -Werror

CC = gcc

RM = @rm -rf

.c.o:
	$(CC) $(CFLAGS) -g -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CLFAGS) -I $(INC_DIR) -o $(NAME) $(OBJS) 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean