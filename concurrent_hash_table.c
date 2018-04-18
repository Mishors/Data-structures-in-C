/*
 * concurrent_hash_table.c
 *
 *  Created on: Apr 16, 2018
 *      Author: Mohamed Raafat
 */

#include "concurrent_hash_table.h"

//Hash table
struct hash_elem** table; //Number of buckets will be determines at run time

/* Number of entries in the hash-table */
int num_buckets;

/*
 *	Return new Hash-table entry and initialize its Mutex lock
 */
static struct hash_elem* get_hash_elem()
{
	struct hash_elem* ptr = (struct hash_elem*) malloc (sizeof(struct hash_elem));
    //Allocated in the right way
    if(ptr != NULL)
    {
    	/* Empty hash-table entry */
        ptr->head = NULL;

        /*If initializing the lock is not successful free the current
         * hash-elem entry and return from function
         */
        if(pthread_mutex_init(&ptr->lock,NULL) != 0)
        {
        	free(ptr);
        	return NULL;
        }
    }
    return ptr;
}

int Hash_init(int numbuckets)
{
	/* Hash-table cannot be zero sized */
	if(numbuckets == 0) return -1;

	num_buckets = numbuckets;

	//Dynamically allocate memory for the hash-table
	table = (struct hash_elem**) malloc (sizeof(struct hash_elem*) * numbuckets);

	//Not allocated in the right way
	if(table == NULL) return -1;

	//Initializing the hash-table (struct hash_elem) entries
	for(int i=0; i<numbuckets; i++)
	{
		/* Initialize the Mutex locks of each entry */
		table[i] = get_hash_elem();
		if(table[i] == NULL) return -1;
	}
	return 0;
}

int Hash_insert(int element)
{
	/* Hash function */
	int bucket_num = element % num_buckets;

	pthread_mutex_lock(&table[bucket_num]->lock);

	struct node* entry_head = table[bucket_num]->head;
	int *elem_ptr = (int *)malloc(sizeof(int));
	*elem_ptr = element;

	if(entry_head == NULL)
	{
		/* Create new list */

		table[bucket_num]->head = get_element(elem_ptr);

	}else{
		/* Push to end of the list	*/
		add_back(entry_head,elem_ptr);
	}

	pthread_mutex_unlock(&table[bucket_num]->lock);

	return 0;
}

int Hash_lookup(int element)
{
	/* Hash function */
	int bucket_num = element % num_buckets;

	pthread_mutex_lock(&table[bucket_num]->lock);
	struct node* entry_head = table[bucket_num]->head;
	if(entry_head == NULL)
	{
		pthread_mutex_unlock(&table[bucket_num]->lock);
		return -1;
	}
	struct node* iter = entry_head;
	while(iter != NULL)
	{
		 int *cur_elem = (int *)(iter->value);
		 if(element == *cur_elem)
		 {
			 pthread_mutex_unlock(&table[bucket_num]->lock);
			 return 0;
		 }
		 iter = iter->next;
	}
	pthread_mutex_unlock(&table[bucket_num]->lock);
	return -1;
}

