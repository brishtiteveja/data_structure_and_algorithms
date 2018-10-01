#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
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
        int maxSubArrayLen(int s, vector<int>& nums) 
        {
            int i=1, j=nums.size(), max = INT_MIN;

            if (windowExist(j, nums, s)) {
                return j;
            } else { // binary search
                while (i<=j)
                {
                    // get mid size
                    int mid = (i+j) / 2;

                    if (windowExist(mid, nums, s)) {
                        i = mid+1;
                        max = mid;
                    } else {
                        j = mid-1;
                    }
                }
            }
        }



        int maxSubArrayLen(vector<int>& nums, int& k)
        {
            // represents the max length required to create the sum
            unordered_map<int, int> m;
            m[0] = -1;
            int sum = 0;
            int maxLen = 0;
            for(int i=0; i<nums.size(); i++)
            {
                sum += nums[i];
                if (!m.count(sum))
                    m[sum] = i;
                if(m.count(sum-k)) // this existence means that for some length we could make sum-k)
                    maxLen = max(maxLen, i - m[sum-k]);
            }


            return maxLen;

        }
};
