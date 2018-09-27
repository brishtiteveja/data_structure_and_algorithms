#include <iostream>
#include <vector>
#include <unordered_map>

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

        vector<vector<int> > permuteUnique(vector<int>& nums)
        {
            unordered_map<int, int> h;
            vector<vector<int> > res;
            if (nums.size() == 1)
            {
                res.push_back(nums);
                return res;
            }

            int i, j;
            for (i=0; i<nums.size(); i++)
            {
                //cout << "i = " << i << endl;
                vector<int> v;
                // insert nums[i] in the hash map
                if (h.find(nums[i]) == h.end())
                    h[nums[i]]++;
                else
                    continue; // nums[i] already appeared
                for(j=0; j<nums.size(); j++)
                {
                    if (j != i) 
                    {
                        v.push_back(nums[j]);
                    }

                }
                //print(v);
                //cout << endl;

                vector<vector <int> > r = permuteUnique(v);

                for(j=0; j<r.size(); j++)
                {
                    int k;
                    vector<int> r2;
                    // push nums[i]
                    r2.push_back(nums[i]);
                    // concatenate nums[i] + r[j]
                    for(k=0; k<r[j].size(); k++)
                    {
                       r2.push_back(r[j][k]); 
                    }

                    //print(r2);
                    //cout << endl;

                    res.push_back(r2);          
                }
            }

            return res;
        }
};

void print(vector<vector<int> > v)
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

int main()
{
    int a[3] = {1, 1, 2};
    int n = 3;
    vector<int> nums(a, a+n);

    Solution sol;
    vector<vector<int> > res = sol.permuteUnique(nums);
    cout << res.size() << endl;

    print(res);

    return 0;
}
