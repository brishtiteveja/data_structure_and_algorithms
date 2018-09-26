#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;


class Solution
{
    public:
        bool isPalindrome(string s) 
        {
            int L = s.size();
            int i,j;

            i =0; j=L-1;
            while(i<j)
            {
                if (s[i++] != s[j--])
                    return false;
            }

            return true;
        }
        /*
         * aba
         * aaaa
         * slls
         */

        /*
         * words[i] ->  (left, right) = (words[i][0->j-1], words[i][j->L])
         * left | right is Palindrome | reversed(left) in hash_table
         * reversed(right) in hash_table | left is Palindrome | right
         */

        vector<vector<int> > palindromePairs(vector<string>& words)
        {
            vector<vector<int> > ans;
            int i, j;

            unordered_map<string, int> dict;
            
            for(i=0; i<words.size(); i++)
            {
                string key = words[i];
                reverse(key.begin(), key.end());
                dict[key] = i;
            }

            if(dict.find("") != dict.end())
            {
                for(i=0; i<words.size(); i++)
                {
                    if(dict[""] == i)
                        continue;

                    if(isPalindrome(words[i])) 
                    {
                        int a[2] = {dict[""], i};
                        vector<int> vs(a, a+2);
                        ans.push_back(vs);
                    }
                }
            }

            for(i=0; i<words.size(); i++)
            {
                for(j=0; j<words[i].size(); j++)
                {
                    string left = words[i].substr(0, j);
                    string right = words[i].substr(j, words[i].size());
                    if(dict.find(left) != dict.end() && isPalindrome(right) && dict[left] != i) 
                    {
                        int a[2] = {i, dict[left]};
                        vector<int> vs(a, a+2);
                        ans.push_back(vs);
                    }

                    if(dict.find(right) != dict.end() && isPalindrome(left) && dict[right] != i) 
                    {
                        int a[2] = {dict[right], i};
                        vector<int> vs(a, a+2);
                        ans.push_back(vs);
                    }
                }
            }

            return ans;
        }

        void printPalindromePairs(vector<string> vs)
        {
            vector<vector<int> > ans = palindromePairs(vs);

            for(int i=0; i<ans.size(); i++)
            {
                cout << "{ ";
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout << ans[i][j];
                    if (j+1 != ans[i].size())
                        cout << ",";
                }
                cout << "} " << "  ";
            }
            cout << endl;

            return;
        }
};

int main()
{
    char s[5][6] = {"abcd", "dcba", "lls", "s", "sssll"};
    vector<string> vs(s, s + sizeof(s)/sizeof(s[0]));

    Solution sol;
    sol.printPalindromePairs(vs);

    char s2[3][4] = {"bat", "tab", "cat"};
    vector<string> vs2(s2, s2 + sizeof(s2)/sizeof(s2[0]));
    sol.printPalindromePairs(vs2);

    return 0;
}

