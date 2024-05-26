CC = gcc
CFLAGS = -Wall -Iinclude
OBJ = src/main.o src/graph.o src/priority_queue.o
DEPS = include/graph.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

google_street_view: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f src/*.o google_street_view
