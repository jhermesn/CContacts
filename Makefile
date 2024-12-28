EXEC = gerenciador

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c contacts.c
OBJS = $(SRCS:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

%.o: %.c contacts.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(EXEC)

.PHONY: all clean
