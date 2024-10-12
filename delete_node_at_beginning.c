
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

void insert_node_at_beginning(node_t **head, int value)
{
    node_t *ext_node;
    
    ext_node = malloc(sizeof(node_t *));
    ext_node->info = value;
    
    if(first != NULL) {
        ext_node->next = *head;
        *head = ext_node;
    } else {
        *head = ext_node;
        ext_node->next = NULL;
    }
}

void insert_node_after_an_index(node_t *head, int pos, int value)
{
    int i = 0;
    node_t *p = head;
    node_t *temp;
    
    do {
    
        p = p->next;
        i++;
        
    } while(i < pos);
    
    temp = malloc(sizeof(node_t));
    temp->info = value;
    
    temp->next = p->next;
    p->next = temp;
}

void delete_node_at_the_beginning(node_t **head)
{
    node_t *temp;
    
    temp = *head;
    *head = (*head)->next;
    
    free(temp);
    temp = NULL;
}

int main()
{
    create_single_linkedlist(&first, 10);
    
    insert_node_at_beginning(&first, 100);
    
    insert_node_after_an_index(first, 6, 200);
    
    insert_node_after_an_index(first, 11, 300);
    
    traverse_linked_list(first);
    
    printf("\n\nLinked list after deleting the first node: -\n\n");
    delete_node_at_the_beginning(&first);
    traverse_linked_list(first);
    
    return 0;
    
}

/** Output: -

Node pos - 0, value - 100
Node pos - 1, value - 1
Node pos - 2, value - 2
Node pos - 3, value - 3
Node pos - 4, value - 4
Node pos - 5, value - 5
Node pos - 6, value - 6
Node pos - 7, value - 200
Node pos - 8, value - 7
Node pos - 9, value - 8
Node pos - 10, value - 9
Node pos - 11, value - 10
Node pos - 12, value - 300


Linked list after deleting the first node: -

Node pos - 0, value - 1
Node pos - 1, value - 2
Node pos - 2, value - 3
Node pos - 3, value - 4
Node pos - 4, value - 5
Node pos - 5, value - 6
Node pos - 6, value - 200
Node pos - 7, value - 7
Node pos - 8, value - 8
Node pos - 9, value - 9
Node pos - 10, value - 10
Node pos - 11, value - 300

**/
