#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

class Solution
{
    public:
        struct ListNode* reverseList(struct ListNode* head)
        {
            ListNode *prev, *cur, *next;

            prev = NULL;
            cur = head;
            if (cur == NULL)
                return head;
            next = cur->next;

            // head->1->3->4->5->NULL
            // NULL<-1<-3<-4<-5<-head

            while(cur != NULL && next != NULL)
            {
                cur->next = prev;
                
                prev = cur;
                cur = next;
                next = next->next;
            }

            if (cur != NULL && next == NULL) {
                cur->next = prev;
                head = cur;
            }

            return head;
        }

        void printList(struct ListNode* head)
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
    struct ListNode* head;

    head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(5); 


    Solution sol;

    sol.printList(head);
    head = sol.reverseList(head);

    sol.printList(head);

    return 0;
}
