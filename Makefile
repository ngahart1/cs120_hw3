#Some variable definitions
CC = gcc
CONSERVATIVE_FLAGS = -std=c99 -pedantic -Wall -Wextra
DEBUGGING_FLAGS = -g #-o0
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

bin: hw3

hw3: hw3.c linked_list.o
	$(CC) -o hw3 hw3.c linked_list.o

#Links the linked_list
linked_list.o: linked_list.c linked_list.h
	$(CC) $(CFLAGS) -c linked_list.c

#'make clean' will remove intermediate and executable files
clean:
	rm -f *.0 hw3 *.gcov
