#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
        int search(int A[], int n, int target)
        {
            int lo, hi;
            lo=0, hi=n-1;

            // find the index of the smallest value using binary search
            // Loop will terminate since mid < hi, and lo or hi will shrink by at least 1
            while(lo < hi)
            {
                int mid = (lo+hi)/2;
                if(A[mid] > A[hi])
                    lo = mid+1;
                else
                    hi=mid;
            }

            // lo==hi is the index of the smallest value
            int rot=lo;
            lo=0;
            hi=n-1;
            // usual binary search and accounting for rotation
            while(lo<=hi)
            {
                int mid = (lo+hi)/2;
                int realmid = (mid+rot)%n;
                if(A[realmid]==target)
                    return realmid;
                if(A[realmid]<target)
                    lo = mid+1;
                else
                    hi = mid-1;
            }

            return -1;
        }
};

int main()
{
    int n = 7;
    int A[7] = {4, 5, 6, 7, 0, 1, 2};

    vector<int> nums(A, A+7);
    int target;

    while(cin >> target)
    {
        Solution sol;
        int pos = sol.search(A, n, target);
        cout << pos << endl;
    }
    
    return 0;
}
