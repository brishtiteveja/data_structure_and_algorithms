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
    	void printList(ListNode *l)
    	{
        	while(l != NULL)
        	{
            	cout << l->val << " ";
            	l = l->next;
        	}
        	cout << endl;
        
        	return;
    	}
		
		ListNode* mergeTwoLists2(ListNode* l1, ListNode *l2)
		{
			ListNode dummy(INT_MIN);	
			
			ListNode *tail = &dummy;

			for(; l1 != NULL && l2 != NULL; )
			{
				if(l1->val < l2->val)
			    {
					tail->next = l1;
					l1 = l1->next;
				} else {
					tail->next = l2;
					l2 = l2->next;
				}
				tail = tail->next;
			}

			if (l1 == NULL)
				tail->next = l2;
			else
				tail->next = l1;

			return dummy.next;
		}
    
        ListNode* mergeTwoLists(ListNode* l1, ListNode *l2)
        {
            /*
                * l1 = []
                * l2 = [1, 3, 4]
            */
            if (l1 == NULL)
                return l2;
            /*
             * l1 = [5, 6]
             * l2 = []
             */
            if (l2 == NULL)
                return l1;


            ListNode *head;
            // increasing order so head should point the list with smaller value at the beginning 
            if (l1->val)
                head = l1;
            else
                head = l2;

			ListNode *pl1 = l1;
			ListNode *pl2 = l2;
            for(; l1 != NULL && l2 != NULL; )
            {
                if (l1->val <= l2->val)
                {
                    /* 
                     l1 -> (1 -> 1 ->1) -> 6 -> 6 -> 8 
                     l2 -> ((2->2->4->5)) -> 10 

                     l1 -> (1-> 1 -> 1) -> ((2->2->4->5)) -> 6 -> 6 -> 8
                        
                     l2 -> 10
                    */
                    ListNode *ln1 = l1->next;    
                    // First find the largest node value in l1 which is smaller than l2 node value
                    // move the l1 node as long as the node is smaller than l2 node value
                    while(l1 != NULL && l1->val <= l2->val)
                    {
                        pl1 = l1; // keep the previous node info
                        l1 = l1->next;
                    }

                    ln1 = pl1->next;
                    pl1->next = l2;


                    while(l2 != NULL && l1 != NULL && l2->val <= l1->val)
                    {
                        pl2 = l2;
                        l2 = l2->next;
                    }

                    l2 = pl2->next;
                    pl2->next = ln1;
                    l1 = ln1;
                    l1 = ln1;

                    if (l1 != NULL)
                        pl1 = l1;

                    if (l2 != NULL)
                        pl2 = l2;
                } else 
                {
                    ListNode *ln1 = l1->next;

                    while(l2 != NULL && l2->val <= l1->val)
                    {
                        pl2 = l2;
                        l2 = l2->next;
                    }

                    pl2->next = l1;
                }
            }

        	if (l2 != NULL && l1 == NULL) {
            	ListNode *head2 = head;
            	while(head2 != NULL && head2->next != NULL) {
                	head2 = head2->next;
            	}
            	head2->next = l2;
        	}

            return head;
        }
};

int main()
{
	ListNode *l1 = new ListNode(1);
	l1->next = new ListNode(1);
	l1->next->next = new ListNode(1);
	l1->next->next->next = new ListNode(5);
	l1->next->next->next->next = new ListNode(5);
	l1->next->next->next->next->next = new ListNode(8);
	l1->next->next->next->next->next->next = new ListNode(10);
	l1->next->next->next->next->next->next->next = new ListNode(10);

	ListNode *l2 = new ListNode(3);
	l2->next = new ListNode(3);
	l2->next->next = new ListNode(4);
	l2->next->next->next = new ListNode(4);
	l2->next->next->next->next = new ListNode(5);
	l2->next->next->next->next->next = new ListNode(5);
	l2->next->next->next->next->next->next = new ListNode(6);
	l2->next->next->next->next->next->next->next = new ListNode(9);
	l2->next->next->next->next->next->next->next->next = new ListNode(10);
	l2->next->next->next->next->next->next->next->next->next = new ListNode(12);

	Solution sol;
	sol.printList(l1);
	sol.printList(l2);
	//ListNode* res = sol.mergeTwoLists(l1, l2);

	//sol.printList(res);
	ListNode* res2 = sol.mergeTwoLists2(l1, l2);
	sol.printList(res2);


	return 0;

}
