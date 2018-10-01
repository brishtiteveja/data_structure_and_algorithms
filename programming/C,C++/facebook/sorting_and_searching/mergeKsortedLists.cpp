#include <iostream>
#include <queue>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){};
};

class Solution
{
    struct qcomp {
    public:
        bool operator()(ListNode* l, ListNode* r)
        {
            return l->val > r->val;
        }
    };
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

ListNode* merge(ListNode* l,ListNode* r)
    {
        ListNode *head,*curr,*l1=l,*l2=r;
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        if(l1->val<l2->val)
        {
            head=l1;
            curr=l1;
            l1=l1->next;
        }
        else
        {
            head=l2;
            curr=l2;
            l2=l2->next;
        }
        while(l1 && l2)
        {
            if(l1->val<l2->val)
            {
                curr->next=l1;
                l1=l1->next;
                curr=curr->next;
            }
            else
            {
                curr->next=l2;
                l2=l2->next;
                curr=curr->next;
            }
        }
        while(l1)
        {
            curr->next=l1;
            l1=l1->next;
            curr=curr->next;
        }
        while(l2)
        {
            curr->next=l2;
            l2=l2->next;
            curr=curr->next;
        }
        return head;
    }

        ListNode* mergeKLists(vector<ListNode*>& lists)
        {
            priority_queue<ListNode*, vector<ListNode*>, qcomp> pq;
            for(ListNode* l : lists)
            {
                if (l != NULL)
                    pq.push(l);
            }

            ListNode dummy(INT_MIN);
            
            ListNode* tail = &dummy;

            cout << endl;
            while(!pq.empty())
            {
                auto top = pq.top();
                pq.pop();
                tail->next = top;
                tail = tail->next;
                if (top->next != NULL)
                    pq.push(top->next);
            }


            return dummy.next;
        }
        // O(nlogk)

    ListNode * mergeUtil(vector<ListNode*>& lists,int low,int high)
    {
        if(low>high)
            return NULL;
        if(low==high)
            return lists[low];
        int mid=(low+high)/2;
        ListNode *l=mergeUtil(lists,low,mid);
        ListNode *r=mergeUtil(lists,mid+1,high);
        if(l==NULL && r==NULL)
            return NULL;
        ListNode *merged=merge(l,r);
        return merged;
    }
    ListNode* mergeKLists2(vector<ListNode*>& lists) {
        int k=lists.size();
        return mergeUtil(lists,0,k-1);
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

    vector<ListNode*> lists;
    lists.push_back(l1);
    lists.push_back(l2);

	ListNode* res2 = sol.mergeKLists(lists);
	sol.printList(res2);

	ListNode* res3 = sol.mergeKLists2(lists);
	sol.printList(res3);


	return 0;

}
