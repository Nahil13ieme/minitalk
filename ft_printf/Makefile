CC = cc
FLAGS = -Wall -Wextra -Werror

NAME = ftprintf.a

LIBFT = ft_printf.h

FILES = ft_printf.c ft_printf_utils.c ft_utils.c

LIBFT_BONUS = ft_printf_bonus.h

OBJS = $(FILES:.c=.o)
OBJS_BONUS = $(FILES_BONUS:.c=.o)

all: ${NAME}

$(NAME): $(FILES)
	$(CC) $(FLAGS) -c $(FILES)
	ar rcs $(NAME) $(OBJS)

bonus: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re