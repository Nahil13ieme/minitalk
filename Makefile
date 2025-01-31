SRCS_SERVER = server.c utils.c
SRCS_CLIENT = client.c utils.c messages.c
OBJ_SERVER = $(SRCS_SERVER:.c=.o)
OBJ_CLIENT = $(SRCS_CLIENT:.c=.o)

FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/ftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -I$(FT_PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: server client

server: $(OBJ_SERVER) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) -o $@ $(OBJ_SERVER) $(FT_PRINTF_LIB)

client: $(OBJ_CLIENT) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) -o $@ $(OBJ_CLIENT) $(FT_PRINTF_LIB)

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	rm -f *.o
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f server client
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re