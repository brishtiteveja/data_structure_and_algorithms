#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
        int trap(vector<int> A)
        {
            int n = A.size();
            int left, right;
            left = 0;right = n-1;
            int maxleft, maxright;
            maxleft = maxright = 0;
            
            int res = 0;

            while(left <= right)
            {
                if(A[left] <= A[right]) {
                    if(A[left] >= maxleft)
                        maxleft = A[left];
                    else
                        res += (maxleft - A[left]);
                    left++;
                }
                else {
                    if(A[right] >= maxright)
                        maxright = A[right];
                    else
                        res += (maxright - A[right]);

                    right--;

                }
                //cout << left << " " << right << endl;
            }

            return res;
        }
};

int main()
{
    int a[12] = {0, 1, 0, 2, 1, 0, 1, 3, 1, 2, 1};
    vector<int> rw(a, a+12);

    Solution sol;
    int res = sol.trap(rw);

    cout << res << endl;

    return 0;
}
