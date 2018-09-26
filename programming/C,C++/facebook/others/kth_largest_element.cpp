#include <iostream>
#include <vector>

class Solution 
{
    private:
        int findKthLargest(vector<int> &nums, int lo, int hi, int k)
        {
            int n = nums.size();
            if (lo == hi)
                return nums[lo];
            swap(nums[k], nums[lo]);

            int left = lo, right = hi, i = lo+1, pivot=nums[lo];
            while (i<=right)
            {
                if(nums[i] < pivot)
                {
                    swap(nums[i], nums[left]);
                    left++;
                    i++;
                } else if (nums[i] == pivot)
                {
                    i++;
                } else
                {
                    swap(nums[i], nums[right]);
                    right--;
                }
            }

            if (k>=left && k<i)
                return nums[left];
            else if (k<left)
                return findKthLargest(nums, lo, left-1, k);
            else
                return findKthLargest(nums, i, hi, k);
        }
};
