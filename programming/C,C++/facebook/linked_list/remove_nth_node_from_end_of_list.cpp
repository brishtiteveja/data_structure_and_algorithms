#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;

    ListNode(int x) : val(x), next(NULL){};
};

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if (!head)
            return NULL;

        ListNode *slow, *fast;
        slow = fast = head;

        int i;
        for (i = 0; i < n; i++)
        {
            if (fast == NULL) // n exceeds the size of the list
                return NULL;
            fast = fast->next;
        }

        if (fast == NULL && slow == head) // n equals the size of the list, therefore delete the first node
        {
            head = head->next;
            delete slow; // delete the first 

            return head;
        }

        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *to_be_deleted; 
        if (slow->next != NULL)
        {
            to_be_deleted = slow->next;
            slow->next = slow->next->next;
            delete to_be_deleted;

            return head;
        }
         



        return NULL;
    }

    void printList(ListNode *head)
    {
         while(head != NULL)
         {
             cout << head->val << " ";
             head = head->next;
         }

         cout << endl;

         return;
     }
};

int main()
{
    ListNode *l1;

    l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(9);
    l1->next->next->next->next = new ListNode(5);
    l1->next->next->next->next->next = new ListNode(10);

    Solution sol;
    sol.printList(l1);
    sol.removeNthFromEnd(l1, 3);
    sol.printList(l1);

    
}
