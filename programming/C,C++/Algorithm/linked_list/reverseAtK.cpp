#include <cstdio>
#include <cstdlib>

/* Link list node */
struct Node 
{
    int data;
    struct Node *next;
}

/* Reverses the linked list in groups of size k and returns pointer to the new head node. */
struct Node *reverse(struct Node *head, int k)
{
    struct Node *current = head;
    struct Node *next = NULL;
    struct Node *prev = NULL;
    int count = 0;

    /* reverse first k nodes of the linked list */
    while (current != NULL && count < k)
    {
        /*
          prev -> cur -> next 

          prev <- cur <- next

                  prev   cur   next
         
         */


        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    /*
   head -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8

    1 <- 2 <- 3  4 <- 5 <- 6 7 <- 8 

         7 <- 8
              ^
              |
    6 -> 5 -> 4 
    ^
    |
    1 <- 2 <- 3


    */
    /* next is now a pointer to (k+1)-th node. Recursively call for the list starting from current. And make rest of the list as next of first node */
    if (next != NULL)
        head->next = reverse(next, k);

    return prev;
}

void push (struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    /* put in the data */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Function to print linked list */
void printList(struct Node *node)
{
    while(node != NULL)
    {
        cout << node->data << " ";
    }
}

int main(void)
{
    struct Node *head = NULL;

    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    cout << endl << "Given linked list" << endl;
    printList(head);
    head = reverse(head, 3);

    cout << endl << "Reversed linked list" << endl;
    printList(head);

    return 0;
}
