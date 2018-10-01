using namespace std;
class Solution {
public:
    
    bool validPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
            if (s[i] != s[j]) {
                int i1 = i, j1 = j - 1, i2 = i + 1, j2 = j;
                while (i1 < j1 && s[i1] == s[j1]) 
                {
                    i1++; 
                    j1--;
                };
                while (i2 < j2 && s[i2] == s[j2]) 
                {
                    i2++; 
                    j2--;
                };
                
                return i1 >= j1 || i2 >= j2; // any of them was palindrome
            }
        
        return true;
    }
    
    bool validPalindrome2(string s) {
        if (s.length() == 0) // empty string
            return true;
        
        
        int nm = 0;
        int ret = 0, reti, retj;
        for(int i=0, j=s.length()-1; i<j; i++, j--)
        {   
            //cout << "i = " << i << ", " << s[i] <<  " j = " << j << " , " << s[j] << endl;
            //cout << "ret = " << ret << endl;
            // ab(d)aaba
            // abaa(d)ba
            if (s[i] != s[j]) {
                nm++;
                if (ret == 1) { // try the other possibility if exists
                    i = reti - 1;
                    j = retj + 1;
                    ret = 0;
                    nm--; // drop number of matches
                    continue;
                }
                
                if (nm == 2)
                    return false;
                
                
                if (s[i+1] == s[j]) {// stay at s[j]
                    if (s[i] == s[j-1]) { // we could stay at s[i] too, save the possibility to try later
                        ret = 1;
                        reti = i;
                        retj = j-1;
                    }
                    
                    j++;
                }
                else if(s[i] == s[j-1]) // stay at s[i]
                    i--;
                else
                    return false;
            }                
        }
        
        return true;
    }
};

