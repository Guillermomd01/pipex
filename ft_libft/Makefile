
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

SRCS			=	ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putstr_fd.c ft_strmapi.c \
					ft_strncmp.c ft_atoi.c ft_isalpha.c ft_putchar_fd.c ft_strtrim.c \
					ft_memcpy.c  ft_strchr.c  ft_strlcpy.c ft_putendl_fd.c ft_putnbr_fd.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_substr.c \
					ft_strdup.c  ft_strlen.c  ft_strrchr.c ft_strjoin.c  ft_itoa.c ft_strlcat.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c ft_striteri.c ft_split.c ft_memmove.c


OBJS			= $(SRCS:.c=.o)



BONUSSRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

BONUSOBJ = $(BONUSSRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

bonus: .bonus

.bonus: $(OBJS) $(BONUSOBJ)
	ar rcs $(NAME) $(OBJS) $(BONUSOBJ) 
	touch .bonus

clean:
				$(RM) $(OBJS) $(BONUSOBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

rebonus:		fclean bonus


.PHONY:			all clean fclean re bonus