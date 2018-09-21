#include <iostream>
#include <cstdio>

// Algorithm
// 1) If Linked list is empty, then make the node as head and return it.
// 2) If value of the node to be inserted is smaller than the value of the node of the head, then insert the node at the start and make it head.
// 3) In a loop, find the appropriate node after which the input node (let 9) is to be inserted. To find the appropriate node start from head, keep moving until you reach a node GN who's value is greater than the input node. The node just before GN is the appropriate node
// 4) Insert the node after the appropriate node found in step 3.
//

struct Node 
{
    int data;
    struct Node* next;
}

void sortedInsert(struct Node** head_ref, struct Node* new_node) 
{
    struct Node* current;
    /* Special case for the head end */
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else 
    {
        /* Locate the node before the point of insertion */
        current = *head_ref;
        while(current->next != NULL &&
                current->next->data < new_node->data)
        {
            new_node->next = current->next;
            current->next = new_node;
        }
    }



}

/* Utility function to create a node */
struct Node *newNode(int new_data) 
{
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
}

/* function to insert a new_node in a list. Note that this function expects a pointer to head_ref as this can modify the head of the input linked list (similar to push()) */
void printList(struct Node *head) 
{
    struct Node* temp = head;
    while(temp != NULL) 
    {
        cout << temp->data ;
        temp = temp->next;
    }
}
/* Drier program to test count function */
int main() {
    /* Start with the empty list */
    struct Node* head = NULL;
    struct Node *new_node = newNode(5);
    sortedInsert(&head, new_node);
    new_node = newNode(10);
    sortedInsert(&head, new_node);
    new_node = newNode(7);
    sortedInsert(&head, new_node);
    new_node = newNode(3);
    sortedInsert(&head, new_node);
    new_node = newNode(1);
    sortedInsert(&head, new_node);
    new_node = newNode(9);
    sortedInsert(&head, new_node);

    cout << endl << "Created Linked List" << endl;
    printList(head);

    return 0;
}
