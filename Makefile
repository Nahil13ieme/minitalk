CC=CC
CFLAGS= -Wall -Wextra -Werror -I
SRCS = server.c client.c


#RULES

%.o = %.c $(SRCS)
	$(cc) $(CFLAGS) -c $@ $<
all:

clean:

fclean:

re:

.PHONY re fclean clean all