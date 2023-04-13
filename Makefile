DIRS=target target/bin target/objs
BIN=target/bin/main
CC=gcc
# CFLAGS=-g -Wall -Wextra -Wpedantic -O1 -std=c17
CFLAGS=-Wall -Wextra -Wpedantic -O1 -std=c17
OBJS=target/objs/main.o target/objs/graph.o target/objs/queue.o target/objs/stack.o

$(shell mkdir -p $(DIRS))
all: $(BIN)

target/bin/main: $(OBJS)
	$(CC) $(CFLAGS) -fsanitize=leak,undefined,address $(OBJS) -o $@
	# $(CC) $(CFLAGS) $(OBJS) -o $@

target/objs/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf target/
