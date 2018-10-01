#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void print(vector<vector<bool> > T)
    {
        int i, j;
        for(i=0; i<T.size(); i++)
        {
            for(j=0; j<T[i].size(); j++)
            {
                if(T[i][j])
                    cout << "T" << " ";
                else
                    cout << "F" << " ";
            }
            cout << endl;
        }

        return;
    }

    bool isMatch(string s, string p) {
        int sn = s.length();
        int pn = p.length();

        if (sn == 0 && pn == 0)
            return true;
        else if (pn == 0)
            return false;

        // replace multiple * with one * in the pattern
        int i, j;
        int ix = 0;
        bool isFirst = true;
        for(i=0; i<pn; i++)
        {
            if(p[i] == '*')
            {
                if(isFirst) {
                    p[ix++] = p[i];
                    isFirst = false;
                }
            } else {
                p[ix++] = p[i];
                isFirst = true;
            }
        }

        pn = ix;

        vector<vector<bool> > W(pn+1, vector<bool>(sn+1, false));


        if (ix > 0 && p[0] == '*')
            W[1][0] = true;

        W[0][0] = true;

        for(i=1; i<=pn; i++)
        {
            for(j=1; j<=sn; j++)
            {
                if(s[j-1] == p[i-1] || p[i-1] == '?')
                    W[i][j] = W[i-1][j-1];
                else if (p[i-1] == '*')
                    W[i][j] = W[i-1][j] || W[i][j-1];
            }
        }

        print(W);

        return W[i-1][j-1];
    }
    
};


int main()
{
    //string s("xaylmz");
    //string p("x?y*z");
    string s("abceb");
    string p("*a*b");

    Solution sol;
    cout << sol.isMatch(s, p) << endl;

    return 0;
}
