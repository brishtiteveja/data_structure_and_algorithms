#include <iostream>
#include <cstdio>

void deleteNode(struct Node *head, struct Node *n) 
{
	// When node to be deleted is head node
	if (head == n) 
	{
		if (head->next == NULL) 
		{
			printf("There is only one node. The list can't be made empty. ");
			return;
		}

		/* copy the data of next node to head */
		head->data = head->next->data;
		
		/* store address of next node */
		n = head->next;

		/* free memory */
		free(n);	

		return;
	}

	// When not first node, follow the normal deletion	
	// find the previous node
	struct Node *prev = head;
	while(prev->next != NULL && prev->next != n)		
	{
		prev = prev->next;
	}

	// Check if node really exists in Linked List
	if (prev->next == NULL)
	{
		cout << "Given node is not present in Linked List" << endl;
		return;
	}

	// Remove node from Linked List
	prev->next = prev->next->next;

	free(n);

	return;
}

/* Utility function to insert a node at the beginning */
void push(struct Node **head_ref, int new_data)
{
	struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}

/* Utility function to print a linked list */
void printList(struct Node *head) 
{ 
    while(head!=NULL) 
    { 
        printf("%d ",head->data); 
        head=head->next; 
    } 
    printf("\n"); 
}

/* Driver program to test above functions */
int main() 
{ 
    struct Node *head = NULL; 
  
    /* Create following linked list 
      12->15->10->11->5->6->2->3 */
    push(&head,3); 
    push(&head,2); 
    push(&head,6); 
    push(&head,5); 
    push(&head,11); 
    push(&head,10); 
    push(&head,15); 
    push(&head,12); 
  
    printf("Given Linked List: "); 
    printList(head); 
  
    /* Let us delete the node with value 10 */
    printf("\nDeleting node %d: ", head->next->next->data); 
    deleteNode(head, head->next->next); 
  
    printf("\nModified Linked List: "); 
    printList(head); 
  
    /* Let us delete the the first node */
    printf("\nDeleting first node "); 
    deleteNode(head, head); 
  
    printf("\nModified Linked List: "); 
    printList(head); 
  
    getchar(); 
    return 0; 
} 
