#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void print(vector<int>& nums)
    {
        int i;
        for(i=0; i<nums.size(); i++)
        {
            cout << nums[i] << " ";
        }

        cout << endl;

        return;
    }

    void moveZeros(vector<int>& nums) {
        int n = nums.size(); 
        int i, j;

        // 1 4 5 7 0 0 3 2 12 0 0 0 1 0 2 0 3 4
        //
        for (i=0, j=0; j<n; )
        {
            // i: find zero
            while(i < n && nums[i] != 0)
            {
                i++;
                j++;
            }

            // j: find non-zero
            while(j < n && nums[j] == 0)
            {
                j++; 
            }

            swap(nums[i++], nums[j++]);

            print(nums);
        }
    }


    // idea of insertion sort O(n^2)
    void moveZeroes1(vector<int>& nums) {
        int n = nums.size();
        int i, j;

        //1 0 0

        //[0,1,0,3, -12, 0, 4]
        // i = 1, 1 0   0 3 -12 0 4
        // i = 3, 1 3   0 0 -12 0 4
        // i = 4, 1 3 -12 0   0 0 4

        // 0 0 0 0 0 4

        // 1 3 -12 0   3 0 4
        for(i=1; i<n; i++)
        {
            int x = nums[i];
            if (x == 0)
                continue;
            for(j=i-1; j>=0; j--)
            {
                if (nums[j] == 0)
                {
                    nums[j+1] = nums[j];
                } else {
                    break;
                }
            }
            nums[j+1] = x;
        }
    }
};

int main()
{
    //int a[5] = {0, 1, 0, 3, 12};
    int a[15] = {1, 2, 4, 0, 1, 0, 0, 2, 3, 4, 6, 0, 0, 8, 0};
    vector<int> nums(a, a + 15);

    Solution sol;
    sol.moveZeros(nums);
    

    return 0;
}
