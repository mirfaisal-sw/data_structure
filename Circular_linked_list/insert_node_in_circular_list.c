
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t *Head = NULL;
void create_circular_linked_list(node_t **head, int arr[], int num_nodes)
{
    node_t *temp;
    node_t *last;
    int i;
    
    temp = (node_t *)malloc(sizeof(node_t));
    temp->data = arr[0];
    *head = temp;
    temp->next = *head;
    last = temp;

    for(i = 1; i < num_nodes; i++)
    {
        temp = (node_t *)malloc(sizeof(node_t));
        temp->data = arr[i];
        
        temp->next = last->next; /*last->next points to head*/
        //temp->next = *head; /*both above and this line has same effect*/
        last->next = temp;
        last = temp;
    }
}

void display_circular_linked_list(node_t *head)
{
    node_t *p = head;    
    do {
        printf("%d\n", p->data);
        p = p->next;        
    }while(p != Head);
}

void insert_node_in_circular_linked_list(node_t **head, int pos, int data)
{
    node_t *temp, *p;
    int i;
    
    if(pos == 0)
    {
        temp = (node_t *)malloc(sizeof(node_t));
        temp->data = data;
        
        if(*head == NULL) /*If circular linked list is empty.*/
        {
            *head = temp;
            temp->next = *head;
        }
        else
        {
            p = *head;
            temp->next = *head;
            
            /*Find last node*/
            while(p->next != *head)
            {
                p = p->next;
            }
            
            p->next = temp;
            temp->next = *head;
            *head = temp;
        }
    }
    else
    {
        p = *head;
        temp = (node_t *)malloc(sizeof(node_t));
        temp->data = data;
        
        for(i = 0; i < pos-1; i++)
            p = p->next;
            
        temp->next = p->next;
        p->next = temp;
    }
    
}

int main()
{
    int A[] = {1, 5, 7, 9, 11, 13, 15};
    create_circular_linked_list(&Head, A, 7);   
    display_circular_linked_list(Head);   
    
    printf("\nCirLinked list after insertion\n");
    insert_node_in_circular_linked_list(&Head, 0, 100);
    display_circular_linked_list(Head);
    
    printf("\nCirLinked list after second insertion\n");
    insert_node_in_circular_linked_list(&Head, 2, 200);
    display_circular_linked_list(Head);
    
    return 0;
}

/*Output: -

1
5
7
9
11
13
15

CirLinked list after insertion
100
1
5
7
9
11
13
15

CirLinked list after second insertion
100
1
200
5
7
9
11
13
15

*/

