SRCS_SERVER = server.c utils.c server_handler.c
SRCS_CLIENT = client.c utils.c client_sender.c
OBJ_SERVER = $(SRCS_SERVER:.c=.o)
OBJ_CLIENT = $(SRCS_CLIENT:.c=.o)


CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I.

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: server client

server: $(OBJ_SERVER)
	$(CC) $(CFLAGS) -o $@ $(OBJ_SERVER)

client: $(OBJ_CLIENT)
	$(CC) $(CFLAGS) -o $@ $(OBJ_CLIENT)

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	rm -f *.o

fclean: clean
	rm -f server client

re: fclean all

.PHONY: all clean fclean re
