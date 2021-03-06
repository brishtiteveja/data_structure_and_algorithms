class Solution 
{
public:
    bool isPalindrome(unsigned long long x)
    {
        vector<unsigned int> t;
        t.reserve(18);

        while(x) 
        {
            t.push_back(x % 10);
            x /= 10;
        }

        for (int i=0, j=t.size()-1; i < j; i++, j--)
        {
            if (t[i] != t[j])
                return false;
        }

        return true;
    }

    int superpalindromesInRange(string L, string R) 
    {
        unsigned long long rangeL = stoull(L);
        unsigned long long rangeR = stoull(R);

        unsigned int squareR = (unsigned int)sqrt(1.0 * rangeR);
        unsigned int limit = (unsigned int)pow(10, (to_string(squareR).length() + 1));

        for(unsigned int x = 1; x < limit; x++)
        {
            unsigned long long scale = 1;
            unsigned long long rev = 0;
            for(auto t=x; t; )
            {
                rev = rev*10 + t%10;
                t /= 10;
                scale *= 10;
            }
            
            // generating palindromes
            unsigned long long p = (rev/10ull) * scale + x;
            auto pp = p * p;
            if (rangeL <= pp && pp <= rangeR && isPalindrome(pp))
                ans++;

            while (true) 
            {
                p = rev * scale + x;
                pp = p * p;

                if (pp > rangeR)
                    break;

                if (rangeL <= pp && isPalindrome(pp))
                    ans++;

                scale *= 10;
            }
        }

        return ans;
    }
};
