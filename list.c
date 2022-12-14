#include "list.h"
#include "node.h"
#include <stdlib.h>
#include <stdio.h>

void printList(node *head)
{
    node *current = head;

    while (current != NULL)
    {

        printf("[%d]->", current->el);
        current = current->next;
    }
    printf("NULL\n");
}



void Duplicate(node* head){
   
    node* new;

    while(head != NULL){
        new = (node*)malloc(sizeof(node));
        if(new == NULL){
            exit(1);
        }
        new->el = head->el;
        new->next = head->next;

        head->next = new;

        head = new->next;
    }
}


int get_list_size(node *head)
{
    int size = 0;
    node *current = head;

    while (current != NULL)
    {

        size++;
        current = current->next;
    }

    return size;
}

void add_last_to_list(node **head, int el)
{

    node* newNode = (node*)malloc(sizeof(node));
    node* last = *head;

    newNode->el = el;

    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode;
        return;
    }

    while(last->next != NULL){
        last = last->next;
    }

    last->next = newNode;
    return;

}

int pop(node **head)
{
    int retel = -1;
    node *next_node = NULL;

    if (*head == NULL)
    {
        return -1;
    }

    next_node = (*head)->next;
    retel = (*head)->el;
    free(*head);
    *head = next_node;

    return retel;
}


int remove_by_index(node** head, int el)
{
    node *temp = *head;
    node *delete;
    int i;
    int size = get_list_size(*head);

    if (el < 0 || el > (size - 1))
    {
       
       return -1;
        
    }

    if (el == 0)
    {
       
     *head = temp->next;
        //temp->next = NULL;
        free(temp);
       
        
    }
    else
    {
        for (i = 0; i < el - 1; i++)
        {
            temp = temp->next;
        }

        delete = temp->next;
        temp->next = temp->next->next;
        delete->next = NULL;
        free(delete);
    }
}

void reverse_list(node **head)
{
    node *prev = NULL;
    node *current = *head;
    node *next = NULL;

    while (current != NULL)
    {
        // store next
        next = current->next;

        // reverse current nodes pekare
        current->next = prev;

        // flytta pekare 1 steg framåt
        prev = current;
        current = next;
    }

    *head = prev;
}






node* remove_by_value(node* head, int val)
{


    if(isEmpty(head) == -1){
       printf("\nListan är tom\n\n");
       
    }else if(Search_node(&head, val) == 0){
       printf("\nFinns inte\n\n");
       
    }else{
    
    
    
    if (!head)
    {
        return head;
    }
    

    while (head && head->el == val)
        head = head->next;

    node *current = head;
    node *prev = NULL;

    while (current)
    {
        if (current->el == val)
        {
            prev->next = current->next;
        }
        else
        {
            prev = current;
        }
        current = current->next;
    }

    return head;
    }
    
}

void push(node **head, int element)
{

    node *new_node;
    new_node = (node *)malloc(sizeof(node));

    new_node->el = element;
    new_node->next = *head;
    *head = new_node;
}

void delete_list(node **head)
{
    node *current = *head;
    node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

void rotate_list_left(node **head, int k)
{

    if (k == 0)
    {
        return;
    }

    node *current = *head;

    int count = 1;

    while (count < k && current != NULL)
    {
        current = current->next;
        count++;
    }

    if (current == NULL)
    {
        return;
    }

    node *Knode = current;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = *head;
    *head = Knode->next;
    Knode->next = NULL;
}

node *rotate_list_right(node *head, int k)
{

    if (head == NULL)
        return head;

    node *tail = head;
    int n = 1;

    while (tail->next != NULL)
    {
        n++;
        tail = tail->next;
    }

    k %= n;

    if (k == 0)
    {
        return head;
    }

    node *newTail = tail;
    tail->next = head;

    int steps_to_new_tail = n - k;

    while (steps_to_new_tail--)
    {
        newTail = newTail->next;
    }

    node *newHead = newTail->next;
    newTail->next = NULL;
    return newHead;

}

// list.c
int insert_specific_index(node **head, int el, int n)
{
    int size = get_list_size(*head);

    node *newNode = (node *)malloc(sizeof(node));
    newNode->el = el;
    newNode->next = NULL;

    if (n < 0 || n > (size-1))
    {
        
        return -1;
    }

    else if (*head == NULL)
    {
        if (n != 0)
        {
            return 0;
        }
        else
        {
            *head = newNode;
        }
    }

    if (*head != NULL && n == 0)
    {
       
        newNode->next = *head;
        *head = newNode;
       return 0;
    }

    node *current = *head;
    node *prev = NULL;

    int i = 0;

    while (i < n)
    {
        prev = current;
        current = current->next;

        if (current == NULL)
        {

            break;
        }
        i++;
    }
    newNode->next = current;
    prev->next = newNode;
    return 3;
   
}

// list.c
void Sort_list(node *head)
{
    node *i = head;
    node *j = head;

    // Bubbel sortering
    while (i != NULL)
    {
        while (j->next != NULL)
        {
            if (j->el > j->next->el)
            {
                int temp = j->el;
                j->el = j->next->el;
                j->next->el = temp;
            }
            j = j->next;
        }
        j = head;
        i = i->next;
    }
}



// list.c
int Search_node(node **head, int el)
{
    node *current = *head;

    while (current != NULL)
    {
        if (current->el == el)
            return 1;

        current = current->next;
    }

    return 0;
}

// list.c
int isEmpty(node *head)
{

    if (head == NULL)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

// list.c
int Get_element_at_index(node *head, int index)
{

    node *current = head;
    int count = 0;
    int size = get_list_size(head);

    if (current == NULL)
    {
        return -1;
    }

    if (index < 0 || index > (size - 1))
    {

        return 0;
    }

    while (current != NULL)
    {
        if (count == index)
        {

            return current->el;
        }
        count++;
        current = current->next;
    }
}

// list.c
int first_occurrence(node *head, int el)
{
    node *current = head;
    int index = 0;
    int size = get_list_size(head);

    

    if (size == 0)
    {

        return -1;
        
    }

    while (current != NULL)
    {

        if (current->el == el)
        {
            
            return index;
            break;
        }
        index++;
        current = current->next;
    }           

   
return 1;
    
}