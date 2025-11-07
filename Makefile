
NAME = pipex
SRC = pipex.c 
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -werror -Wextra
RM = rm -f


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)



clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re