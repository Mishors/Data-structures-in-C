# Data Structures in C

This project includes implementation of basic data structures written in C language. 

## Data Structures in this project

Singly linked list is implemented and support the basic operations done on the list and also Hash-table is implemented using arrays and the linked list (implemented in the project) to resolve collision of hashed keys.

## Singly Linked List

### Supported Opearations

* get_element - Allocate memory for new node then initializes its value with the input "value"and set its next node to NULL
* get_tail - Get the tail of the list i.e: last element
* add_front - Add element to be before the head of the list (i.e: to be the new head)
* add_back - Add element to be after the tail of the list (i.e: to be the new tail)
* remove_head - Remove head node and the next to head becomes the new head
* remove_tail - Remove the tail of the list
* remove_element - Removes the first occurrence of the input value from the list. Hint: If the removed node is the head the next to head becomes the new head (Implemented for integer Linked Lists ONLY)


## Hash-Table

### Supported Opearations

* get_hash_elem - Allocate memory to new hash_elem and initialize its fields key,value and hash
* get_hash_value - Returns hash value of the given key string
* find - Checks whether the key is in the table or not returns true if found else otherwise
* get_value - Returns the value of the given key Null if not found
* insert - Insert the key-value pair to the hash table Hint: (If the key is found the function replaces the old value with the new value)



