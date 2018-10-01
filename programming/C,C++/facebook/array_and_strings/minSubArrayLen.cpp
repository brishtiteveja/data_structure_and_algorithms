#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
        int minSubArrayLen0(int s, vector<int>& nums) {
            int n = nums.size();
            if (n==0)
                return 0;
        
            int i, j, l;
            for(l=1; l<=n; l++) {
                for(j=0; j < n-l+1; j++) {
                    int sum = 0;
                    for(i=j; i<j+l; i++) {
                        sum += nums[i];
                    }
                    if (sum >= s)
                        return l;
                }
            }
        
            return 0;
        }

        bool windowExist(int size, vector<int> nums, int s)
        {
            int sum = 0;
            for(int i=0; i<nums.size(); i++)
            {
                if(i>=size)
                    sum -= nums[i-size];
                sum += nums[i];

                if (sum >= s)
                    return true;
            }

            return false;
        }

        // O(nlogn) solution
        int minSubArrayLen2(int s, vector<int>& nums) 
        {
            int i=1, j=nums.size(), min = 0;

            while (i<=j)
            {
                // get mid size
                int mid = (i+j) / 2;
                if (windowExist(mid,nums, s)) {
                    j = mid-1;
                    min = mid;
                } else {
                    i = mid+1;
                }
            }
        }



        int minSubArrayLen(int s, vector<int>& nums)
        {
            int n = nums.size();
            int start = 0, sum=0, minlen = INT_MAX;
            for(int i=0; i<n; i++)
            {
                sum += nums[i];

                while(sum >= s)
                {
                    minlen = min(minlen, i-start+1); 
                    sum = sum - nums[start];
                    start++;
                }
            } // O(n) solution

            return minlen == INT_MAX ? 0 : minlen;
        }
};
