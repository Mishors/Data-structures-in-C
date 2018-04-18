#Variables declarations
OBJECTS = main.o  concurrent_hash_table.o  linked_list.o 

CC = gcc

CFLAGS = -c -Wall

all: hash_table

hash_table: $(OBJECTS)
	$(CC) $(OBJECTS) -o concurrent_hash_table

main.o: main.c
	$(CC) $(CFLAGS) main.c

concurrent_hash_table.o: concurrent_hash_table.c
	$(CC) $(CFLAGS) concurrent_hash_table.c

Linked_list.o : linked_list.c
	$(CC) $(CFLAGS) linked_list.c

clean: 
	rm -rf *o concurrent_hash_table



	
