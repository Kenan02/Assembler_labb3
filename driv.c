#include "driv.h"
#include "list.h"
#include "node.h"
#include <stdio.h>

void listSize(node *head)
{

    printf("\n Listans storlek: %d", get_list_size(head));
}



void driv_isEmpty(node *head)
{

    if (isEmpty(head) == -1)
    {
        printf("\nListan är tom\n\n");
    }
    else
    {
        printf("\nListan innehåller element\n\n");
    }
}

void driv_get_element_at_index(node *head)
{
    int index;

    printf("\nAnge index: \n\n");
    scanf("%d", &index);
    {
        if (Get_element_at_index(head, index) == -1)
        {
            printf("\nGår inte att hämta något, listan är tom\n\n");
        }
        else if (Get_element_at_index(head, index) == 0)
        {
            printf("\nIndex utom räckhåll, försök igen\n\n");
        }
        else
        {
            printf("Element [%d] ligger på det angivna indexet [index: %d]\n", Get_element_at_index(head, index), index);
        }
    }
}

void driv_Search_node(node *head)
{
    int func_val;
    printf("Ange ett element för att se om det finns i listan eller inte: ");
    scanf("%d", &func_val);
    if (Search_node(&head, func_val))
    {
        printf("\n%d finns\n", func_val);
    }
    else
    {
        printf("\n%d finns inte\n", func_val);
    }
}

void sort(node *head)
{
    printf("\nListan före sortering: \n");
    printList(head);
    Sort_list(head);
    printf("\nListan efter Sortering: \n");
    printList(head);
}

void driv_first_occurrence(node *head)
{

    int func_val;
    printf("Ange tal för att hitta första förkomst: ");
    scanf("%d", &func_val);

    if (first_occurrence(head, func_val) == -1)
    {
        printf("\nListan är tom\n\n");
    }
    else if (first_occurrence(head, func_val) == 1)
    {
        printf("\nAngivna talet finns inte i listan\b\b");
    }
    else
    {
        printf("\nFörsta förekomsten av det angivna elementet [%d] ligger på index [%d]\n\n", func_val, first_occurrence(head, func_val));
    }
}

void driv_insert_specific_index(node *head)
{
    int el, n;

    printf("Ange elementet samt indexet du vill lägga till på: ");
    scanf("%d %d", &el, &n);
    int tmp = insert_specific_index(&head, el, n);

    if (tmp == -1)
    {
        printf("\nOgiltig inmatning, försök igen\n\n");
    }
    if (tmp == 3)
    {
        printf("\nElementet har lagts till på det angivna indexet\n\n");
    }
}

void driv_remove_by_index(node **head)
{
    int el;
    printf("Ange index: ");
    scanf("%d", &el);

    remove_by_index(head, el);
}


void driv_remove_by_value(node *head)
{
    node* tmp;
    int func_val;
    printf("Ange ett element du vill ta bort: ");
    scanf("%d", &func_val);

  
   remove_by_value(head, func_val);


  
    
   
    
}




void print_start_adress(node *head)
{
    int *adr = &head->el;
    printf("%p\n", adr);
}
