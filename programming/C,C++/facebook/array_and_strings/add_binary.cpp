#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
    public:
        // 0 + 0 + 0 = 0, c = 0    
        // 0 + 0 + 1 = 0, c = 0    
        //
        // 0 + 1 + 0 = 1   , c =0 
        // 0 + 1 + 1 = 2->0, c =1 
        //
        // 1 + 0 + 0 = 1   ,  c = 0
        // 1 + 0 + 1 = 2->0,  c = 1 
        //
        // 1 + 1 + 0 = 2->0, c = 1
        // 1 + 1 + 1 = 3->1, c = 1
        string addBinary(string a, string b)
        {
            string r;
            int l1 = a.length();
            int l2 = b.length();

            int i, j, sum, carry, n1, n2;
            carry = 0;

            for(i=l1-1, j=l2-1; i>=0 || j>=0 ; )
            {
                if (i>=0 && j>=0)
                {
                    n1 = a[i]-'0';
                    n2 = b[j]-'0';
                    sum = n1 + n2 + carry;
                    i--;
                    j--;
                } else if (j<0)
                {
                    n1 = a[i]-'0';
                    sum = n1 + carry;
                    i--;
                } else if (i<0) 
                {
                    n2 = b[j]-'0';
                    sum = n2 + carry;
                    j--;
                } 

                if (sum == 1)
                {
                    carry = 0;
                } else if (sum >= 2)
                {
                    sum = sum - 2;
                    carry = 1;
                }

                if (sum == 0)
                    r.push_back('0'); 
                else
                    r.push_back('1'); 
            }

            if (carry == 1)
                r.push_back('1');

            reverse(r.begin(), r.end());

            return r;
        }
};

int main()
{
    string a("1010");
    string b("1011");

    Solution sol;
    string r = sol.addBinary(a, b);

    cout << r << endl;

    return 0;
}
