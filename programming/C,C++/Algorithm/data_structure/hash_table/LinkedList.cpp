#include "LinkedList.h"

// Constructs the empty linked list object
// Creates the head and sets length to zero.
LinkedList::LinkedList()
{
    head = new Item;
    head->next = NULL;
    length = 0;
}

// Inserts an item at the end of the list
void LinkedList::insertItem(Item* newItem)
{
    // handling the first item in the list
    if (!head->next)
    {
        head->next = newItem;
        length++;
        return;
    }

    Item *prev = head;
    Item *cur = head;
    while(cur) 
    {
        prev = cur;
        cur = cur->next;
    }

    prev->next = newItem;
    newItem->next = NULL;
    length++;
}

// Removes an item from the list by item key
// Returns true if the operation is successful
bool LinkedList::removeItem(string itemKey) {
    if(!head->next)
        return false;

    Item* prev = head;
    Item* cur = head;
    while(cur) {
        if(cur->key == itemKey) 
        {
            prev->next = cur->next;
            delete cur;
            length--;
            return true;
        }
        prev = cur;
        cur = cur->next;
    }

    return false;
}

// Searches for an item by its key
// Returns a reference to first match.
// Returns a NULL pointer if no match is found.
Item* LinkedList::getItem(string itemKey)
{
    Item* prev = head;
    Item* cur = head;
    
    while(cur) 
    {
        prev = cur;
        if ((prev != head) && (prev->key == itemKey))
            return prev;
        cur = cur->next;
    }
    
    return NULL;
}

// Displays list contents to the console window.
void LinkedList::printList()
{
    if(length == 0)
    {
        cout << "\n{ }\n";
        return;
    }

    Item* prev = head;
    Item* cur = head;

    cout << "\n{ ";
    while(cur) {
        prev = cur;
        if (prev != head)
        {
            cout << prev->key;
            if(prev->next)
                cout << ", ";
            else
                cout << " ";
        }
        cur = cur->next;
    }
    cout << "}\n";
}

// Returns the length of the list.
int LinkedList::getLength()
{
    return length;
} 

// De-allocates list memory when the program terminates.
LinkedList::~LinkedList()
{
    Item* prev = head;
    Item* cur = cur;
    while(cur) {
        prev = cur;
        cur = cur->next;
        if (cur)
            delete prev;
    }
}
