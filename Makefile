NAME = pipex
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

SRC = pipex.c
OBJ = $(SRC:.c=.o)
LIBFT = ft_libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C ft_libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make clean -C ft_libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C ft_libft

re: fclean all
