#include <cstdio>
#include <cstdlib>

struct Node
{
    int data;
    struct Node *next;
}

void removeLoop(struct Node *loop_node, struct Node *head) {
	struct Node *ptr1, *ptr2;
	
 	/* Set a pointer to the beginning of the Linked List and move it one by one to find the first node which is part of the Linked list  
	*/
	ptr1 = head;
	while (1)
	{
		/* Now start a pointer from loop_node and check if it ever reaches ptr2 */
		ptr2 = loop_node;	
		while (ptr2->next != loop_node && ptr2->next != ptr1) 
		{
			ptr2 = ptr2->next;
		}
		
		/* If pt2 reached ptr1 then there is a loop. So break the loop */
		if (ptr2->next == ptr1)
			break;

		/* If ptr2 didn't reach ptr1 then there is a loop. So break the loop */
	    ptr1 = ptr1->next;
	}

	ptr2->next = NULL;
}

/* This function detects and removes loop in the list. If loop was there in the list when it returns 1, otherwise returns 0 */
int detectAndRemoveLoop(struct Node *list)
{
    struct Node *slow_p, *fast_p;
    slow_p = list;
    fast_p = list;

    while(slow_p && fast_p && fast_p->next) 
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;

        if (slow_p == fast_p)
        {
            removeLoop(slow_p, list);
            return 1;
        }
    }

    return 0;
}

void printList(struct Node *node);

int main() 
{
    struct Node *head = newNode(50); 
    head->next = newNode(20); 
    head->next->next = newNode(15); 
    head->next->next->next = newNode(4); 
    head->next->next->next->next = newNode(10); 
  
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next; 
  
    detectAndRemoveLoop(head); 
  
    printf("Linked List after removing loop \n"); 
    printList(head); 
    return 0; 
}
