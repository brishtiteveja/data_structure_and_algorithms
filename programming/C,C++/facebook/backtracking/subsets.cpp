#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        void print(vector<int> nums) 
        {
            int i;
            for(i=0; i<nums.size(); i++)
            {
                cout << nums[i] << " ";
            }

            cout << endl; 

            return;
        }

        void print2(vector<vector<int> > v)
        {
            int i, j;
            for(i=0; i<v.size(); i++)
            {
                for(j=0; j<v[i].size(); j++)
                {
                    cout << v[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }

        vector<vector<int> > subsets(vector<int>& nums)
        {
            vector<vector<int> > res;
            if (nums.size() == 0)
            {
                return res;
            }
            if (nums.size() == 1)
            {
                res.push_back(nums);
                return res;
            }

            int i, j;
            for (i=0; i<nums.size(); i++)
            {
                vector<int> v;
                for(j=i+1; j<nums.size(); j++)
                {
                    v.push_back(nums[j]);
                }

                vector<vector <int> > r = subsets(v);

                vector<int> r2;
                r2.push_back(nums[i]);
                res.push_back(r2);
                r2.clear();

                for(j=0; j<r.size(); j++)
                {
                    int k;
                    // push nums[i]
                    r2.push_back(nums[i]);
                    // concatenate nums[i] + r[j]
                    for(k=0; k<r[j].size(); k++)
                    {
                       r2.push_back(r[j][k]); 
                    }


                    res.push_back(r2);          
                    r2.clear();
                }
            }

            return res;
        }
};

int main()
{
    int a[3] = {3, 1, 2};
    int n = 3;
    vector<int> nums(a, a+n);

    Solution sol;
    vector<vector<int> > res = sol.subsets(nums);
    cout << res.size() << endl;

    sol.print2(res);

    return 0;
}
