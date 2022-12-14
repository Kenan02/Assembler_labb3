#ifndef LIST_H
#define LIST_H
#include "node.h"



void printList(node* head);
void Duplicate(node* head);
int get_list_size(node* head);

void add_last_to_list(node** head, int el);

int insert_specific_index(node** head, int el, int n);

node* remove_by_value(node* head, int val);

int remove_by_index(node** head, int n);

void delete_list(node** head);

void reverse_list(node** head);

void rotate_list_left(node** head, int k);

node* rotate_list_right(node* head, int k);

void Sort_list(node* head);

int isEmpty(node* head);

int Search_node(node** head, int el);

int Get_element_at_index(node* head, int index);

int first_occurrence(node* head, int el);


int pop(node** head);

void push(node** head, int element);

#endif