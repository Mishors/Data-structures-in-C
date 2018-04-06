#include "hash_table.h"
#include <stdlib.h>

//Hash table
struct node* table[MAX_BUCKETS];


struct hash_elem* get_hash_elem(char* key, char* value, unsigned long hash)
{
	struct hash_elem* ptr = (struct hash_elem*) malloc (sizeof(struct hash_elem));
    //Allocated in the right way
    if(ptr != NULL)
    {
        ptr->key = key;
        ptr->value = value;
        ptr->hash = hash;
    }
    return ptr;
}

unsigned long get_hash_value(char* key)
{
    unsigned long hash = 0;
    while(*key)
    {
        hash = hash * MULTIPLIER + *key;
        key++;
    }
    return hash%MAX_BUCKETS;
}

boolean find (char* key)
{
	 unsigned long hash = get_hash_value(key);
	 struct node* head = table[hash];
	 if(head == NULL) return FALSE;
	 struct node* iter = head;
	 while(iter != NULL)
	 {
		 struct hash_elem *elem = (struct hash_elem *)(iter->value);
		 char* curr_key = elem->key;
		 int res = strcmp(key,curr_key);
		 if(res == 0) return TRUE;
		 iter = iter->next;
	 }
	 return FALSE;
}

char* get_value(char* key)
{
	//Key not found
	if(!find(key))return NULL;
	unsigned long hash = get_hash_value(key);
	struct node* iter = table[hash];
	while(iter != NULL)
	{

		 struct hash_elem *elem = (struct hash_elem *)(iter->value);
		 char* curr_key = elem->key;
		 int res = strcmp(key,curr_key);
		 char* value = (char*) malloc(sizeof(char*));
	     strcpy(value,elem->value);
		 if(res == 0) return value;
		 iter = iter->next;
	}
	return NULL;
}

void insert(char* key, char* value)
{
    unsigned long hash = get_hash_value(key);
    struct hash_elem* element = get_hash_elem(key,value,hash);
    struct node* elem_node = get_element(element);
    struct node* head = table[hash];
    if(head == NULL)
    {
        table[hash] = elem_node;
        return;
    }else if(find(key)){
    	struct node* iter = head;
    	while(iter != NULL)
    	{
    		struct hash_elem *elem = (struct hash_elem *)(iter->value);
    		char* curr_key = elem->key;
    		int res = strcmp(key,curr_key);
    		if(res == 0){
    			elem->value = value;
    			return ;
    		}
    		iter = iter->next;
    	}
    }
    add_back(head,element);
}





