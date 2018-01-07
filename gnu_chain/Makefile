SRCS = src/main.c
PROG = gc
CC = gcc
CP_CFLAGS = -DPRINT_ME 
CP_CFLAGS += -Wall
LK_CFLAGS =  
# OBJS = $(patsubst %.c,%.o,${SRCS})
OBJS = $(SRCS:.c=.o)

$(PROG): $(OBJS)
	$(CC) $(LK_CFLAGS) -o $@ $^
	@echo make done!

%.o: %.c
	$(CC) $(CP_CFLAGS) -c -o $@ $^

.PHONY: clean
clean:
	rm -f $(PROG) $(OBJS)