
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

int main()
{
    int A[] = {1, 5, 7, 9, 11, 13, 15};
    create_circular_linked_list(&Head, A, 7);   
    display_circular_linked_list(Head);    
    return 0;
}

/**Output: -
  1
  5
  7
  9
  11
  13
  15
**/
