#include <iostream>
#include <vector>

using namespace std;

class RegexMatching
{
    private:
        bool matchRegexRecursive(string text, string pattern, int pos1, int pos2)
        {
            int i, j;
            // if pos2 has reached end pf pattern, then it means pos2 should also reach end of text for match to happen
            if (pos2 == pattern.length())
                return pos1 == text.length(); 

            // if next character is not * , then it means either current value at pattern and text should be same or current value at pattern should be . in which case you can skip one character of text

            if (pos2 == pattern.length() - 1 || pattern[pos2+1] != '*') 
            {
                return (pos1 < text.length() && 
                        (text[pos1] == pattern[pos2] || pattern[pos2] == '.')) && 
                        matchRegexRecursive(text, pattern, pos1+1, pos2+1);
            }

            // if we have case like abc and ad*bc so here we totally skip d*
            if (matchRegexRecursive(text, pattern, pos1, pos2+2))
                return true;

            // For case like abbc and ab*c match first b with b* and then next b to c. If that does not work then try next b with b* and then c with c and so on.
            // if pattern current val is . then skip one character at time from text till we either reach end of text or a match is found

            while(pos1 < text.length() && (text[pos1] == pattern[pos2] || pattern[pos2] == '.'))
            {
                if (matchRegexRecursive(text, pattern, pos1+1, pos2+2))
                {
                    return true;
                }

                pos1++;

            }

            return false;
        }

    public:
        bool matchRegexRecursive(string str, string pattern)
        {
            return matchRegexRecursive(str, pattern, 0, 0);
        }

        bool matchRegex(string t, string p)
        {
            vector<vector<bool> > T(t.length() + 1, vector<bool> (p.length() + 1));

            T[0][0] = true;

            int i, j;

            for (i=1; i<p.length(); i++)
            {
                if(p[i-1] == '*' && T[0][i-1])
                    T[0][i] = true;
            }

            for(i=1; i < t.length(); i++)
            {
                for(j=1; j < p.length(); j++)
                {
                    cout << "i = " << i << " j = " << j << endl;
                    if (p[j-1] == '.' || p[j-1] == t[i-1])
                    {
                        T[i][j] = T[i-1][j-1];
                    } else if (p[j-1] == '*')
                    {
                        if (j >=2) {
                            T[i][j] = T[i][j-2];

                            if (p[j-2] == '.' || p[j-2] == t[i-1])
                            {
                                T[i][j] = T[i][j] || T[i-1][j];
                            }
                        } else {
                            T[i][j] = T[i][j] || T[i-1][j];
                        }
                    } else 
                    {
                        T[i][j] = false;
                    }
                }
            }

            return T[t.length()][p.length()];
        }
};

class Solution2 {
public:
    bool isMatchRecursive(string s, string p) {
        if (p.empty())    return s.empty();

        if ('*' == p[1])
            // x* matches empty string or at least one character: x* -> xx*
            // *s is to ensure s is non-empty
            return (isMatch(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p));
        else
            return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1));
    }

    bool isMatch(string s, string p) {
        /**
         * f[i][j]: if s[0..i-1] matches p[0..j-1]
         * if p[j - 1] != '*'
         *      f[i][j] = f[i - 1][j - 1] && s[i - 1] == p[j - 1]
         * if p[j - 1] == '*', denote p[j - 2] with x
         *      f[i][j] is true iff any of the following is true
         *      1) "x*" repeats 0 time and matches empty: f[i][j - 2]
         *      2) "x*" repeats >= 1 times and matches "x*x": s[i - 1] == x && f[i - 1][j]
         * '.' matches any single character
         */
        int m = s.size(), n = p.size();
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));

        f[0][0] = true;
        for (int i = 1; i <= m; i++)
            f[i][0] = false;
        // p[0.., j - 3, j - 2, j - 1] matches empty iff p[j - 1] is '*' and p[0..j - 3] matches empty
        for (int j = 1; j <= n; j++)
            f[0][j] = j > 1 && '*' == p[j - 1] && f[0][j - 2];

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (p[j - 1] != '*')
                    f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
                else
                    // p[0] cannot be '*' so no need to check "j > 1" here
                    f[i][j] = f[i][j - 2] || (s[i - 1] == p[j - 2] || '.' == p[j - 2]) && f[i - 1][j];

        return f[m][n];
    }
};

int main()
{

    Solution2 sol;
    bool r = sol.isMatch(string("Tushar"), string("Tushar*a*b*"));
    cout << r << endl;


    return 0;
}
