#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution
{
    public:
        ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
        {
            ListNode *p1, *p2, *p3, *r;

            p1=l1;
            p2=l2;

            r = p3 = NULL; 

            int carry, sum;
            carry = 0;

            while(p1 != NULL || p2 != NULL) 
            {
                if (p1 != NULL && p2 != NULL)
                {
                    sum = p1->val + p2->val + carry;
                    p1 = p1->next;
                    p2 = p2->next;
                } else if (p2 == NULL) 
                {
                    sum = p1->val + carry;
                    p1 = p1->next;
                } else if (p1 == NULL)
                {
                    sum = p2->val + carry;
                    p2 = p2->next;
                }

                if(sum >= 10)
                {
                    sum = sum-10;
                    carry = 1;
                } else {
                    carry = 0;
                }

                if (p3 == NULL)
                {
                    p3 = new ListNode(sum);
                    r = p3;
                } else {
                    p3->next = new ListNode(sum);
                    p3 = p3->next;
                }
            }

            if (carry == 1)
            {
                p3->next = new ListNode(carry);
                p3 = p3->next;
            }

            p3 = NULL;

            return r;
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
    ListNode *l1, *l2;

    l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(9);

    l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(6);

    // l1->2->4->3->9->NULL
    // l2->5->6->6->NULL
    // l ->7->0->0->1->NULL

    Solution sol;
    sol.printList(l1);
    sol.printList(l2);
    ListNode *r = sol.addTwoNumbers(l1, l2);
    sol.printList(r);

    
}
