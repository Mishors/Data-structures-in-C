/*
 * concurrent_hash_table.h
 *
 *  Created on: Apr 16, 2018
 *      Author: Mohamed Raafat
 */

#ifndef CONCURRENT_HASH_TABLE_H_
#define CONCURRENT_HASH_TABLE_H_

#include "linked_list.h"
#include <pthread.h>

struct hash_elem
{
    /*	Head node of the linked list that handles
     *	collision in the same location
     */
	struct node* head;
	/* Lock for each entry in the hash-table */
    pthread_mutex_t lock;
};

/*
 *	Initializes hash table with the  specified number of
 *	buckets. In addition, set up one lock for each bucket
 *	and one list per bucket .
 *	Returns 0 if successful -1 otherwise
 */
int Hash_init(int numbuckets);

/*
 *	Insert a number element to the hash table.
 *	Return 0 if the number has been successfully added to
 *	the hash table, or -1 otherwise.
 *	Hint: If duplicate is found it will Return 0
 */
int Hash_insert(int element);

/*
 *	Lookup the value element . If it is in the hash table,
 *  return 0; otherwise, return -1.
 */
int Hash_lookup(int element);


#endif /* CONCURRENT_HASH_TABLE_H_ */
