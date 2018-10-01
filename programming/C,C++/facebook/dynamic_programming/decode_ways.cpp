#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    void print(vector<int>& v) {
        int i;
        for(i=0; i<v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
        
        return;
    }

    void prints(vector<string>& v) {
        int i;
        for(i=0; i<v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
        
        return;
    }
    
    void print2(vector<vector<int> >& v) {
        int i, j;
        for(i=0; i<v.size(); i++) {
            for(j=0; j<v[i].size(); j++) {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        
        return;
    }

    void prints2(vector<vector<string> >& v) {
        int i, j;
        for(i=0; i<v.size(); i++) {
            for(j=0; j<v[i].size(); j++) {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        
        return;
    }

    vector<vector<string> > subsetStrings(string s)
    {
        vector<string> sv;
        vector<vector<string> > res;
        if (s.length() == 1)
        {
            sv.push_back(s);
            res.push_back(sv);
            return res;
        }

        int i, sn=s.length();
        for(int i=1; i <= sn; i++)
        {
            string pre = s.substr(0, i);
            sv.push_back(pre);
            res.push_back(sv);

            string posts = s.substr(i, sn); 

            vector<vector<string> > post;

            if (posts.length() > 0)
                post = subsetStrings(posts);
            
            if (post.size() > 0)
            {
                res.clear();
                sv.clear();
                for(int j=0; j<post.size(); j++)
                {
                    // append post[j] to sv
                    sv.insert(sv.end(), post[j].begin(), post[j].end());
                }
                res.push_back(sv);
            }

            cout << s << endl;
            cout << "i = " << i << endl;
            cout << "--------" << endl;
            prints2(res);

        }

        return res;
    }

    int numDecodings2(string s) {
        map<int, char> m;
        
        for(int i=0; i<26; i++) {
            m[i+1] = 'A' + i;
        }
        
        vector<vector<string> >ss = subsetStrings(s);

        prints2(ss);

        return ss.size();
    }

    int numDecodings(string s)
    {
        int n = s.length();
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        dp[n-1] = (s[n-1] != '0') ? 1 : 0;

        for(int i=n-2; i>=0; i--)
            if (s[i] == '0')
                continue;
            else
                dp[i] = (stoi(s.substr(i, 2) ) <= 26)? dp[i+1] + dp[i+2] : dp[i+1]

        return dp[0];

    }


};
    

int main()
{
    string data("22");

    Solution sol;
    int m = sol.numDecodings(data);
    cout << m << endl;

}

