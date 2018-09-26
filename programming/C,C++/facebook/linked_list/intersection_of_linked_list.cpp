#include <iostream>
#include <unordered_map>

using namespace std;


// Method 1 (Use two loops) O(mn)
// Method 2 (Use a visited flag) O(m + n)
// Method 3 (Using difference of node count)

struct ListNode {
     int val;
     ListNode *next;
    // bool visited (method 2) 
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    // Method 3
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int l1, l2;
        l1 = l2 = 0;

        ListNode *hA, *hB;
        hA = headA;
        hB = headB;

        // Find the length of both the list
        while(true)
        {
            if (hA != NULL)
            {
                l1++; 
                hA = hA->next;
            }

            if (hB != NULL)
            {
                l2++;
                hB = hB->next;
            }
            
            if (hA == NULL && hB == NULL)
            {
                break;
            }
        }

        // get the diff of node counts
        int diff = abs(l1-l2);

        int k = diff;
        hA = headA;
        hB = headB;
        while(k > 0)
        {
            if (l1 >= l2)
                hA = hA->next;
            else
                hB = hB->next;

            k--;
        }


        while(true)
        {
            if (hA == NULL || hB == NULL) 
                return NULL;

            if (hA == hB)
                return hA;
            hA = hA->next;
            hB = hB->next;
        }

        return NULL;

    }
    
    //
    ListNode *getIntersectionNodeWithHashMap(ListNode *headA, ListNode *headB)
    {
        unordered_map<int, bool> hm;       

        while(headA != NULL)
        {
            hm[headA->val] = true;
            headA = headA->next;
        }

        while(headB != NULL)
        {
            if(hm.find(headB->val) != hm.end())
            {
                return headB;
            }

            headB = headB->next;
        }

        return NULL;
    }
};


//
//              
//    8 -> 9   
//           \
//    3-> 1 -> 5 -> 6 -> 4 
int main()
{
    ListNode *headA = new ListNode(3);
    headA->next = new ListNode(1);
    headA->next->next = new ListNode(5);
    headA->next->next->next = new ListNode(6);
    headA->next->next->next->next = new ListNode(4);

    ListNode *headB = new ListNode(8);
    headB->next = new ListNode(9);
    headB->next->next = headA->next->next;


    Solution sol;

    ListNode *intersectionNode = sol.getIntersectionNode(headA, headB);

    if(intersectionNode != NULL)
        cout << intersectionNode->val << endl;
    else 
        cout << "No intersection" << endl;

}
