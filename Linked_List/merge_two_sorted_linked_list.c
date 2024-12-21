#include <stdio.h>
#include <stdlib.h>

typedef struct node {    
    int data;
    struct node *next;
}node_t;

/*Create a linked list
* Returns Head of the linked list.
*/
node_t *create_single_linked_list(int arr[], int num_nodes)
{
    node_t *head;
    node_t *p, *temp;
    int i;
    
    head = (node_t *)malloc(sizeof(node_t));
    
    p = head;
    p->data = arr[0];
    p->next = NULL;
    
    for(i = 1; i < num_nodes; i++)
    {
        temp = (node_t *)malloc(sizeof(node_t));
        p->next = temp;
        temp->data = arr[i];
        
        temp->next = NULL;
        p = temp;
    }
    
    return head;
}

void display_linked_list(node_t const *head)
{
    node_t const *temp = head;
    int i = 0;
    
    printf("\nLinked list data: \n");
    while(temp != NULL)
    {
        printf("Node - %d, Data - %d\n", i, temp->data);
        temp = temp->next;
        i++;
    }
}

/*Merge two sorted linked list
* Returns Head of the merged list.
*/
node_t *merge_two_sorted_linked_list(node_t *first, node_t *second)
{
    node_t *third = NULL; /*this will point to the merged list*/
    node_t *last = NULL;
    
    /* Start a merged linked list with head as "third",
     * by picking the smallest node.
     */
    if(first->data < second->data)
    {
        third = last = first;
        first = first->next;
        last->next = NULL;
    }
    else
    {
        third = last = second;
        second = second->next;
        last->next = NULL;
    }
    
    while((first != NULL) && (second != NULL))
    {
        if(first->data < second->data)
        {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else
        {
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }
    
    return third;
}

int main()
{
    node_t *head_first = NULL;
    node_t *head_second = NULL;
    node_t *merged_linked_list = NULL;
    
    int len;
    
    int arr_first[] = {3, 5, 9, 11, 13, 15, 17, 19, 21};
    len  = sizeof(arr_first)/sizeof(arr_first[0]);
    
    head_first = create_single_linked_list(arr_first, len);
    display_linked_list(head_first);
    
    int arr_sec[] = {2, 4, 6, 8, 10, 12};
    len  = sizeof(arr_sec)/sizeof(arr_sec[0]);
    head_second = create_single_linked_list(arr_sec, len);
    display_linked_list(head_second);
    
    merged_linked_list = merge_two_sorted_linked_list(head_first, head_second);
    display_linked_list(merged_linked_list);
    
    return 0;
}

/*Output: -

Linked list data: 
Node - 0, Data - 3
Node - 1, Data - 5
Node - 2, Data - 9
Node - 3, Data - 11
Node - 4, Data - 13
Node - 5, Data - 15
Node - 6, Data - 17
Node - 7, Data - 19
Node - 8, Data - 21

Linked list data: 
Node - 0, Data - 2
Node - 1, Data - 4
Node - 2, Data - 6
Node - 3, Data - 8
Node - 4, Data - 10
Node - 5, Data - 12

Linked list data: 
Node - 0, Data - 2
Node - 1, Data - 3
Node - 2, Data - 4
Node - 3, Data - 5
Node - 4, Data - 6
Node - 5, Data - 8
Node - 6, Data - 9
Node - 7, Data - 10
Node - 8, Data - 11
Node - 9, Data - 12

*/
