#include <bits/stdc++.h>
using namespace std;

// Linked list Node structure
struct Node
{
    char c;
    struct Node *next;
};

// Function to create new node in a linkedlist
Node* newNode(char c)
{
    Node *temp = new Node;
    temp->c = c;
    temp->next = NULL;
    return temp;
};

int compare(Node *list1, Node *list2)
{
    // Traverse both lists.
    while (list1 && list2 && list1->c == list2->c) 
    {
        list1 = list1->next;
        list2 = list2->next;
    }

    // If both lists are not empty, compare mismatched characters
    if (list1 && list2)
        return (list1->c > list2->c) ? 1 : -1;

    // If either of the two lists has reached end
    if (list1 && !list2) return 1;
    if (!list1 && list2) return -1;

    return 0;
}

int main()
{
    Node *list1 = newNode('g');
    list1->next = newNode('e');
    list1->next->next = newNode('e');
    list1->next->next->next = newNode('k');
    list1->next->next->next->next = newNode('s');
    list1->next->next->next->next->next = newNode('b');

    Node *list2 = newNode('g');
    list2->next = newNode('e');
    list2->next->next = newNode('e');
    list2->next->next->next = newNode('k');
    list2->next->next->next->next = newNode('s');
    list2->next->next->next->next->next = newNode('a');

    cout << compare(list1, list2);

    return 0;
}
