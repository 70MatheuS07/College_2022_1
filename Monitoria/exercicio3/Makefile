APPNAME: Debugar

all: main

CC = gcc
override CFLAGS += -g -Wno-everything -pthread -lm

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.c' -print)
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

%.d: %.c
	@set -e; rm -f $@; \
	$(CC) -MM $(CFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

include $(DEPS)

main: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o main

clean:
	rm -f $(OBJS) $(DEPS) main