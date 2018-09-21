#include <cstdio>
#include <cstdlib>
#include <cstdbool>

/* Link list node */
struct Node
{
    int data;
    struct Node* next;
}

/* A utility function to insert a node at the beginning of a linked list */
void push(struct Node** head_ref, int new_data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    (*head_ref) = new_node;
}

/* A utility function to check if given data is present in a list */
bool isPresent(struct Node *head, int data)
{
    struct Node *t = head;

    while (t != NULL)
    {
        if (t->data == data) 
        {
            return 1;
        }

        t = t->next;
    }

    return 0;
}

/* FUnction to get union of two linked lists head1 and head2 */
struct Node *getUnion(struct Node *head1, struct Node *head2)
{
    struct Node *result = NULL;
    struct Node *t1 = head1, *t2 = head2;

    // Insert all elements of list1 to the result list
    while (t1 != NULL)
    {
        push(&result, t1->data);
    }

    // Insert those elements of list2 which are not present in result list
    while (t2 != NULL)
    {
        if(!isPresent(result, t2->data))
            push(&result, t2->data);
        t2 = t2->next;
    }

    return result;
}

/* Function to get intersection of two linked lists head1 and head2 */
struct Node *getIntersection(struct Node *head1, struct Node *head2) 
{
    struct Node *result = NULL;
    struct Node *t1 = head1;

    // Traverse list1 and search each element of it in list2. If the element is present in list 2, then insert the eleement to result
    while (t1 != NULL) 
    {
        if (isPresent(head2, t1->data))
            push(&result, t1->data);
        t1 = t1->next;
    }

    return result;
}

/* A utility function to print a linked list */
void printList(struct Node *node)
{
    while (node != NULL) 
    {
        cout << node->data;
        node = node->next;
    }
}

int main()
{
    /* Start with the empty list */
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct Node* intersecn = NULL;
    struct Node* unin = NULL;

    push(&head1, 20);
    push(&head1, 4);
    push(&head1, 15);
    push(&head1, 10);

    push(&head2, 10);
    push(&head2, 2);
    push(&head2, 4);
    push(&head2, 8);

    intersecn = getIntersection(head1, head2);
    unin = getUnion(head1, head2);

    cout << endl << "First list is" << endl;
    printList(head1);
    cout << endl << "Second list is" << endl;
    printList(head2);
    cout << endl << "Intersection list is" << endl;
    printList(intersecn);
    cout << endl << "Union list is" << endl;
    printList(unin);

    return 0;
}
