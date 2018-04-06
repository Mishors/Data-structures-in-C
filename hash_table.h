#ifndef HASH_TABLE_H_INCLUDED
#define HASH_TABLE_H_INCLUDED

#include "linked_list.h"
#define MAX_BUCKETS 1000
#define MULTIPLIER 31

enum _boolean {
   FALSE = 0,
   TRUE = 1
};

typedef enum _boolean boolean;

struct hash_elem
{
    char* key;
    char* value;
    unsigned long hash;
};

/*
 * Allocate memory to new hash_elem and initialize its fields key,value and hash
 */
struct hash_elem* get_hash_elem(char* key, char* value, unsigned long hash);


/*
 * Returns hash value of the given key string
 */
unsigned long get_hash_value(char* key);

/*
 * Checks whether the key is in the table or not returns true if found
 * else otherwise
 */
boolean find (char* key);

/*
 * Returns the value of the given key Null if not found
 */
char* get_value(char* key);

/*
 *	Insert the key-value pair to the hash table
 *	Hint: (If the key is found the function replaces the old value
 *	with the new value)
 */
void insert(char* key, char* value);


#endif // HASH_TABLE_H_INCLUDED

