#include <iostream>
#include <vector>

using namespace std;

// A positive integer is a superpalindrome if it is a palindrome and it is also the square of a palindrome


class Solution
{
    public:
        inline long long pali(long long val, long long mid=-1)
        {
            long long ans = val;

            // set the middle digit 
            // -1 is the case of not using any middle digit
            if (mid != -1)
                ans = ans*10 + mid;

            // add the digit from the lower rank
            for(;val; val/=10)
            {
                ans += ans*10 + val%10;
            }

            return ans;
        }

        inline bool is_pali(long long val, long long l, long long r)
        {
            if (val < l || val > r)
                return false;

            long long t = 0;

            // create the number t which has the digits in reverse order
            for(auto v=val; v; v/=10)
            {
                t = t*10 + v%10;
            }

            // check whether t equals to val
            return t==val;
        }

        vector<int> superpalindromesInRange(string L, string R)
        {
            vector<int> ans;
            long long l = stoll(L), r = stoll(R);
            int a = (l <= 1 && 1 <= r) + (l <= 4 && 4<= r) + (l <= 9 && 9 <= r);

            if (l <= 1 && 1 <= r)
                ans.push_back(1);

            if (l <= 4 && 4 <= r) 
                ans.push_back(4);

            if (l <= 9 && 9 <= r)
                ans.push_back(9);

            for(long long i = 1; i < 34000; i++)
            {
                auto val = pali(i);
                if (val * val > r) 
                    break;
                for(int m=-1; m<10; m++)
                {
                    val = pali(i, m);
                    if(is_pali(val*val, l, r))
                    {
                        a += 1;
                        ans.push_back(val);
                    }
                }
            }

            return ans;
        }
};

void print(vector<int> r)
{
    int i;
    for(i=0; i<r.size(); i++)
    {
        cout << r[i] << " ";
    }
    cout << endl;
}

int main()
{
    string L("1");
    string R("10000");

    Solution sol;
    vector<int> ans = sol.superpalindromesInRange(L, R); 

    print(ans);

    return 0;
}

