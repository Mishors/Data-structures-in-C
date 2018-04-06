#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

typedef struct node
{
    void* value;
    struct node* next;
};

/*
* Prints the values of the list from the head node to Tail node
*/
void print_list(struct node* head);

/*
* allocate memory for new node then initializes its value with the input "value"
* and set its next node to NULL
*/
struct node* get_element(void* value);

/*
* Get the tail of the list i.e: last element
*/
struct node* get_tail(struct node* head);

/*
*   Add element to be before the head of the list (i.e: to be the new head)
*/
struct node* add_front(struct node* head, void* value);


/*
*   Add element to be after the tail of the list (i.e: to be the new tail)
*/
struct node* add_back(struct node* head, void* value);


/*
* removed head node and the next to head becomes the new head
*/
struct node* remove_head(struct node* head);

/*
*  Remove the tail of the list
*/
void remove_tail(struct node* head);

/*
* Removes the first occurrence of the input value from the list
* Hint: If the removed node is the head the next to head becomes the new head
* (Implemented for integer Linked Lists ONLY)
*/
void remove_element(struct node* head, int value);

#endif // LINKED_LIST_H_INCLUDED

