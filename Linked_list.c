#include "linked_list.h"

void print_list(struct node* head)
{
 if(head == NULL) return;
 struct node* iter = head;
 while(iter != NULL)
 {
 	printf("%d ",*(int *)iter->value);
	iter = iter->next;
 }
 printf("\n");
}

struct node* get_element(void* value)
{
    struct node* ptr = (struct node*) malloc (sizeof(struct node));
    //Allocated in the right way
    if(ptr != NULL)
    {
        ptr->value = value;
        ptr->next = NULL;
    }
    return ptr;
}

struct node* get_tail(struct node* head)
{
    if(head == NULL)return NULL;

    struct node* iter = head; //iterator

    while (iter->next != NULL)
    {
        iter = iter->next;
    }

    return iter;
}

struct node* add_front(struct node* head, void* value)
{
    struct node* element = get_element(value);
    //Not Allocated in the right way
    if(element == NULL) return head;

    element->next = head;

    return element;
}



struct node* add_back(struct node* head, void* value)
{
    struct node* element = get_element(value);

    struct node* tail = get_tail(head);

    //Not Allocated in the right way
    if(element == NULL) return NULL;

    tail->next = element;

    return element;
}


struct node* remove_head(struct node* head){
    if(head == NULL) return NULL;
    //set the new head to the next node
    struct node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

void remove_tail(struct node* head){
    if(head == NULL) return NULL;

    struct node* prev;
    struct node* tail;
    struct node* next;
    tail = head;
    /*
    If head is the Only node so remove it
    |HEAD| ----> NULL
    */
    if(tail->next == NULL)
    {
        remove_head(head);
        return;
    }
    prev = head;
    tail = head->next;
    /*
    If 2 Nodes remove Tail
    |HEAD| ----> |TAIL| ---> NULL
    */
    if(tail->next == NULL)
    {
        prev->next = NULL;
        free(tail);
        return ;
    }
    /*
    If linked list of (size > 2 Nodes)
    |Prev| -----> |Tail| ----> |Next| ---->
    */
    next = tail->next;
    while(next != NULL)
    {
        prev = prev->next;
        tail = tail->next;
        next = next->next;
    }
    prev->next = NULL;
    free(tail);

}


void remove_element(struct node* head, int value)
{
    if(head == NULL) return;
    //If head is the target node so remove it
    //and set the new head to the next node
    if(*(int *)head->value == value)
    {
        remove_head(&head);
        return;
    }

    struct node* prev = head;
    struct node* current = head->next;
    while(current != NULL)
    {
        if(*(int *)current->value == value)
        {
            struct node* temp = current->next;
            prev->next = temp;
            free(current);
            return;
        }
    }

}
