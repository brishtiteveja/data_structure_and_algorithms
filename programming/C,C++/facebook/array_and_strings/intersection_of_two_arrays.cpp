#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
typedef unordered_multimap<int, int> ummi;

class Solution {
    public:
        vector<int> intersect(vector<int>& num1, vector<int>& num2)
        {
            unordered_multimap<int,int> m;
            pair<int,int> p;

            int i;
            int n;
            for(i=0; i<num1.size(); i++)
            {
                n = num1[i];
                p = make_pair(n, 0);
                m.insert(p);
            }

            for(i=0; i<num2.size(); i++)
            {
                n = num2[i];    

                // find all the keys 
                pair<ummi::iterator,
                     ummi::iterator > range = m.equal_range(n); 

                ummi:: iterator pi;
                for(pi=range.first; pi!=range.second; pi++)
                {
                    // just set for one of them
                    if(pi->second == 0)
                    {
                        pi->second = 1;
                        break; 
                    }
                }
                
            }

            vector<int> res;
            unordered_multimap<int,int>::iterator pi;
            for(pi=m.begin(); pi!=m.end(); pi++)
            {
                if(pi->second == 1)
                    res.push_back(pi->first);
            }

            return res;
        };
};

void print(vector<int> res)
{
    int i;
    for(i=0; i<res.size(); i++)
    {
        cout << res[i] << " ";
    }

    cout << endl;
}

int main()
{
    //int l1=3;
    //int n1[3] = {4, 9, 5};
    int l1=4;
    int n1[4] = {1, 2, 2, 1};
    vector<int> nums1(n1, n1+l1); 

    //int l2=5;
    //int n2[5] = {9, 4, 9, 8, 4};
    int l2 = 2;
    int n2[2] = {2, 2};
    vector<int> nums2(n2, n2+l2);

    vector<int> res;    
    Solution sol;
    res = sol.intersect(nums1, nums2);

    print(res);

    return 0;
}
