#Some variable definitions
CC = gcc
CONSERVATIVE_FLAGS = -std=c99 -pedantic -Wall -Wextra
DEBUGGING_FLAGS = -g -o0
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

bin: hw3

hw3: hw3.c menu_options.o
	$(CC) -o hw3 hw3.c menu_options.o linked_list.o

menu_options.o: menu_options.c menu_options.h linked_list.o
	$(CC) $(CFLAGS) -c menu_options.c linked_list.o

#Links the linked_list
linked_list.o: linked_list.c linked_list.h  
	$(CC) $(CFLAGS) -c linked_list.c

#'make clean' will remove intermediate and executable files
clean:
	rm -f *.0 hw3 *.gcov
