#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *next;
} node_t;

node_t *first = NULL;

void create_single_linkedlist(node_t **head, int num_nodes)
{
    node_t *p, *temp;
    int i;
    
    temp = malloc(sizeof(node_t));
    temp->info = 1;
    temp->next = NULL;
    
    *head = temp;
    p = *head;
    
    for(i = 0; i < num_nodes - 1; i++)
    {
        temp = malloc(sizeof(node_t));
        temp->info = (i+2);
        
        p->next = temp;
        temp->next = NULL;
        p = temp;
    }
}

void traverse_linked_list(node_t *head)
{
    node_t *p;
    int index = 0;
    
    p = first;
    
    while(p != NULL)
    {
        printf("Node pos - %d, value - %d\n", index, p->info);
        p = p->next;
        index++;
    }
}

void delete_node_at_the_end(node_t *head)
{
    node_t *p = head;
    node_t *q;
    
    while(p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    
    free(q->next);
    q->next = NULL;
}

/*other method*/
void delete_node_at_the_end_method2(node_t *head)
{
    node_t *second_last = head;
    
    while(second_last->next->next != NULL)
    {
        second_last = second_last->next;
    }
    
    free(second_last->next);
    second_last->next = NULL;
}

int main()
{
    create_single_linkedlist(&first, 10);
    traverse_linked_list(first);
    
    printf("\n\nLinked list after deleting last node: -\n\n");
    delete_node_at_the_end(first);
    traverse_linked_list(first);
    
    printf("\n\nLinked list after deleting last node: -\n\n");
    delete_node_at_the_end_method2(first);
    traverse_linked_list(first);
    
    return 0;    
}

/*Output: -

Node pos - 0, value - 1
Node pos - 1, value - 2
Node pos - 2, value - 3
Node pos - 3, value - 4
Node pos - 4, value - 5
Node pos - 5, value - 6
Node pos - 6, value - 7
Node pos - 7, value - 8
Node pos - 8, value - 9
Node pos - 9, value - 10


Linked list after deleting last node: -

Node pos - 0, value - 1
Node pos - 1, value - 2
Node pos - 2, value - 3
Node pos - 3, value - 4
Node pos - 4, value - 5
Node pos - 5, value - 6
Node pos - 6, value - 7
Node pos - 7, value - 8
Node pos - 8, value - 9


Linked list after deleting last node: -

Node pos - 0, value - 1
Node pos - 1, value - 2
Node pos - 2, value - 3
Node pos - 3, value - 4
Node pos - 4, value - 5
Node pos - 5, value - 6
Node pos - 6, value - 7
Node pos - 7, value - 8

*/
