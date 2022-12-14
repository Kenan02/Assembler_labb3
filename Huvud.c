#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include "driv.h"
#include "node.h"
#include "list.h"
#include "node.h"

int main()
{
    bool end = false;
    node *head = NULL;
    int val;
    int func_val;
    

    while (!end)
    {
        printf("\n<--------------------------------------------------->\n");
        printf("0. Avsluta \n");
        printf("1. Skriv ut listan\n");
        printf("2. Skriv ut listasns storlek\n");
        printf("3. Lägg till ett heltal sist i listan\n");
        printf("4. lägg till ett heltal (valfri plats)\n");
        printf("5. Ta bort ett givet tal\n");
        printf("6. ta bort ett givet tal (valfri plats)\n");
        printf("7. Töm listan\n");
        printf("8. Vänd på listan\n");
        printf("9. Skifta listan ett steg åt vänster (lägg första heltalet sist)\n");
        printf("10. skifta hela listan ett steg åt höger (lägg sista heltalet talet först)\n");
        printf("11. Sortera listan (lägsta heltalet först)\n");
        printf("12. Skriv ut startadresse för listan\n");
        printf("13. Kolla om listan är tom eller inte\n");
        printf("14. Kolla om ett visst element finns i listan eller inte\n");
        printf("15. Returnera elementet på en viss plats i listan\n");
        printf("16. Returnera platsen för första förekomst av ett vistt element i listan\n");
        printf("17. Duplicera\n");
        printf("<--------------------------------------------------->\n\n");

        printf("Gör ditt val: ");

        scanf("%d", &val);

        switch (val)
        {
        case 0:
            end = true;
            break;

        case 1:
            printList(head);
            break;
        case 2:
            listSize(head);
            break;
        case 3:
            printf("\nAnge talet du vill lägga till sist i listan: ");
            scanf("%d", &func_val);
            add_last_to_list(&head, func_val);
            break;
        case 4:

            driv_insert_specific_index(head);
            break;

        case 5:

            driv_remove_by_value(head);

            break;

        case 6:

            driv_remove_by_index(&head);
            break;

        case 7:
            delete_list(&head);
            break;

        case 8:
            reverse_list(&head);
            break;

        case 9:
            printf("\nLista före rotation:\n");
            printList(head);
            rotate_list_left(&head, 1);
            printf("\nLista efter rotation:\n");
            printList(head);

            break;

        case 10:
            printf("\nListan före rotation: \n\n");
            printList(head);
            head = rotate_list_right(head, 1);
            printf("\nListan efter efter rotation: \n\n");
            printList(head);
            break;

        case 11:

            sort(head);
            break;

        case 12:
            print_start_adress(head);
            break;

        case 13:
            driv_isEmpty(head);
            break;

        case 14:
            driv_Search_node(head);
            break;

        case 15:

            driv_get_element_at_index(head);
            break;

        case 16:

            driv_first_occurrence(head);
            break;

            case 17:

            Duplicate(head);
            break;

        default:
            printf("\nFelaktig inmatning försök igen\n");
        }
    }

    return 0;
}