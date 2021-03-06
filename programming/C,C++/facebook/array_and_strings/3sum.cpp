#include <iostream>
#include <vector>

using namespace std;


class Solution
{
    public:
        vector<vector<int> > threeSum(vector<int> &num)
        {
            vector<vector<int> > res;

            sort(num.begin(), num.end());

            for(int i = 0; i<num.size(); i++)
            {
                int target = -num[i];

                int front = i+1;
                int back = num.size() - 1;

                while(front < back)
                {
                    int sum = num[front] + num[back];

                    // Finding answer which start from number num[i]
                    if (sum < target)
                    {
                        front++;
                    } else if (sum > target)
                    {
                        back--;
                    } else
                    {
                        vector<int> triplet(3, 0);
                        triplet[0] = num[i];
                        triplet[1] = num[front];
                        triplet[2] = num[back];
                        res.push_back(triplet);
                        
                        // Processing of duplicates of number 2
                        // Rolling the front pointer to the next different number
                        while (front < back && num[front] == triplet[1])
                            front++;

                        while(front < back && num[back] == triplet[2])
                            back--;
                    }
                }

                // Processing duplicates of Number 1
                while (i+1 < num.size() && num[i+1] == num[i])
                    i++;
            }

            return res;
        }
};

int main()
{
    int ns[6] = {-1, 0, 1, 2, -1, -4};
    vector<int> nums(ns, ns+6); 

    Solution sol;
    vector<int> res = sol.threeSum(nums);

    return 0;
}
