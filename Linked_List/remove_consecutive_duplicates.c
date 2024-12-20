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

int find_length_of_linked_list(node_t *head)
{
    node_t *temp;
    int count = 0;
    
    temp = head;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }    
    return count;
}

void display_linked_list(node_t const *head)
{
    node_t *temp = head;
    int i = 0;    
    while(temp != NULL)
    {
        printf("Node - %d, Data - %d\n", i, temp->data);
        temp = temp->next;
        i++;
    }
}

node_t *reverse_linked_list(node_t *head)
{
    node_t *p = head;
    node_t *q = NULL;
    node_t *r = NULL;    
    node_t *rev_head;
   
    while(p != NULL)
    {
        r = q;
        q = p;
        
        p = p->next;        
        q->next = r;
    }

    rev_head = q;    
    return rev_head;
}

/*Find duplicate nodes and remove from a linked list*/
void remove_consecutive_duplicates_from_linked_list(node_t *head)
{
    node_t *p, *q;
    node_t *temp;
    
    q = head;
    p = head->next;
    
    while(p != NULL)
    {
        if((p->data) != (q->data))
        {
            q = p;
            p = p->next;
        }
        else {
            
            q->next = p->next;
            p->next = NULL;
            free(p);
            
            p = q->next;
        }
    }
}

int main()
{
    node_t *head = NULL;
    node_t *rev_head;
    node_t *p;
    
    int arr[10] = {3, 5, 5, 9, 11, 13, 15, 17, 19, 21};
    int len  = sizeof(arr)/sizeof(arr[0]);
    
    head = create_single_linked_list(arr, len);
    p = head;
    
    printf("\n=> length of linked list - %d\n", find_length_of_linked_list(head));
    display_linked_list(p);
    
    rev_head = reverse_linked_list(head);
    printf("\n=> Linked list after reversing\n");
    display_linked_list(rev_head);
    
    printf("\n=> Linked list after removing concecutive duplicates\n");
    remove_consecutive_duplicates_from_linked_list(rev_head);
    display_linked_list(rev_head);
    
    return 0;
}

/*Output: -
=> length of linked list - 10

Node - 0, Data - 3
Node - 1, Data - 5
Node - 2, Data - 5
Node - 3, Data - 9
Node - 4, Data - 11
Node - 5, Data - 13
Node - 6, Data - 15
Node - 7, Data - 17
Node - 8, Data - 19
Node - 9, Data - 21

=> Linked list after reversing
Node - 0, Data - 21
Node - 1, Data - 19
Node - 2, Data - 17
Node - 3, Data - 15
Node - 4, Data - 13
Node - 5, Data - 11
Node - 6, Data - 9
Node - 7, Data - 5
Node - 8, Data - 5
Node - 9, Data - 3

=> Linked list after removing concecutive duplicates
Node - 0, Data - 21
Node - 1, Data - 19
Node - 2, Data - 17
Node - 3, Data - 15
Node - 4, Data - 13
Node - 5, Data - 11
Node - 6, Data - 9
Node - 7, Data - 5
Node - 8, Data - 3

*/
