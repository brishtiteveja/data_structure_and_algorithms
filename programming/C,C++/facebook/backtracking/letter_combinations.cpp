#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
        vector<string> letterCombinations(string digits)
        {
            vector<string> result;
            if (digits.empty())
                return result;
            
            string vs[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
            vector<string> v(vs, vs+10);

            result.push_back("");

            for(int i=0; i<digits.size(); i++)
            {
                int num = digits[i] - '0';
                if (num < 0 || num > 9)
                    break;

                const string& candidate = v[num];
                if (candidate.empty())
                    continue;

                vector<string> tmp;
                for(int j=0; j<candidate.size(); j++)
                {
                    for(int k=0; k<result.size(); k++)
                    {
                        tmp.push_back(result[k] + candidate[j]);
                    }
                }

                result.swap(tmp);
            }

            return result;
        }
        
};

int main()
{
    string digits("23");

    Solution sol;
    vector<string> v = sol.letterCombinations(digits);

    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
