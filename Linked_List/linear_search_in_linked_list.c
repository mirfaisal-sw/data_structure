
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

void delete_node_at_nth_position(node_t *head, int pos)
{
    node_t *temp = head;
    node_t *p;
    int i = 0;
    
    do {        
        temp = temp->next;
        i++;        
    } while(i < (pos-1));
    
    p = temp->next;
    temp->next = temp->next->next;
    free(p);
    
    p->next = NULL;    
}

node_t *search_a_node(node_t *p, int key)
{
    if(p == NULL)
        return NULL;
        
    while(p != NULL)
    {
        if(p->info == key)
            return p;        
        p = p->next;
    }
    return NULL;
}

int main()
{
    node_t *found_node;
    
    create_single_linkedlist(&first, 10);
    traverse_linked_list(first);
    
    found_node = search_a_node(first, 5);
    printf("\n\nFound node's value - %d\n", found_node->info);
  
    return 0;    
}

/** Output: -
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

Found node's value - 5
**/
