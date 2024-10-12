
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

int count_no_of_nodes_in_linked_list(node_t *p)
{
    int count = 0;
    while(p != NULL)
    {
        p = p->next;
        count++;
    }
    
    return count;
}

/*Reverse the linked list using reversing elements*/
void reverse_linked_list_rev_element(node_t *head)
{
    int *arr, i;
    int count;
    node_t *p = head;
    
    count = count_no_of_nodes_in_linked_list(p);
   
    /*Allocate a linear array to store data from each node.*/
    arr = (int *)malloc(sizeof(int)*count);
    
    while(p != NULL)
    {
        arr[i] = p->info;
        p = p->next;
        i++;
    }
    
    p = head;
    i--;
    
    while(p != NULL)
    {
        p->info = arr[i];
        p = p->next;
        i--;
    }
}

int main()
{
    node_t *found_node;
    
    create_single_linkedlist(&first, 10);
    traverse_linked_list(first);
    
    printf("\nNo of nodes in linked list - %d\n", count_no_of_nodes_in_linked_list(first));

    /*Rverese linked list by reversing elements*/
    reverse_linked_list_rev_element(first);
    printf("\nLinked list after reversing it: \n");
    traverse_linked_list(first);
    
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

No of nodes in linked list - 10

Linked list after reversing it: 
Node pos - 0, value - 10
Node pos - 1, value - 9
Node pos - 2, value - 8
Node pos - 3, value - 7
Node pos - 4, value - 6
Node pos - 5, value - 5
Node pos - 6, value - 4
Node pos - 7, value - 3
Node pos - 8, value - 2
Node pos - 9, value - 1

**/
  
