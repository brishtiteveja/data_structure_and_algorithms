class Solution {
    bool isAlphaNumeric(char c) {
        if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9')
            return true;
        else
            return false;
    }
public:
    bool isPalindrome(string s) {
        if (s.length() == 0) // empty string
            return true;
        
        
        // Boundary cases -- need to think about
        for(int i=0; i<s.length(); i++)
            s[i] = toupper(s[i]);
        
        for(int i=0, j=s.length()-1; i<j; i++, j--)
        {
            while(!isAlphaNumeric(s[i]))
                i++;
            while(!isAlphaNumeric(s[j]))
                j--;
            
            // ,.:aa          
            if (i < j && s[i] != s[j])
                return false;
        }
        
        return true;
    }
};

