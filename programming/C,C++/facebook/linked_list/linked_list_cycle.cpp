#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) 
            return false;

        ListNode *sp, *fp; 
        sp=fp = head;

        while (true) {
            // No cycle
            if (fp == NULL || sp == NULL)
                return false;
            if (fp->next == NULL)
                return false;

            sp = sp->next;
            fp = fp->next->next;

            if (sp == fp)
                return true;
        }

        return false;
    }

    /*
     * Function to remove loop.
     * loop_node --> Pointer to one of the loop nodes
     * head --> Pointer to the start node of the linked list
     */
    void removeLoop(ListNode *loop_node, ListNode *head)
    {
        ListNode *ptr1, *ptr2;

        /*
         * First find the first node of the loop
         * Set a pointer to the beginning of the Linked List and move it one by one and see whether it's reachable from the loop_node. The first reachable node from the loop_node should be the first node of the loop
         */
        ptr1 = head;
        while (true)
        {
            /* Now start a pointer from loop_node and check if it ever reaches ptr2 */ 
            ptr2 = loop_node;
            while (ptr2->next != loop_node && ptr2->next != ptr1)
            {
                ptr2 = ptr2->next; 
            }

            /* If ptr2 reached ptr1 then there is a loop. So break the loop */
            if (ptr2->next == ptr1)
                break;

            ptr1 = ptr1->next;
        }

        /*
         * After the end of loop ptr2 is the last node of the loop. So make next of ptr2 as NULL
         * Finall remove the loop
         */
        ptr2->next = NULL;
    }

};


//
//             7 <- 2 
//             |    ^
//             u    |
//    3-> 1 -> 5 -> 6 
int main()
{
    ListNode *intermediate;
    ListNode *head = new ListNode(3);
    intermediate = head->next = new ListNode(1);
    head->next->next = new ListNode(5);
    head->next->next->next = new ListNode(6);
    head->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next= new ListNode(7);
    head->next->next->next->next->next->next= intermediate;

    Solution sol;

    cout << sol.hasCycle(head) << endl;

}
