#include <iostream>

class RegexMatching
{
    private:
        bool matchRegexRecursive(string text, string pattern, int pos1, int pos2)
        {
            // if pos2 has reached end pf pattern, then it means pos2 should also reach end of text for match to happen
            if (pos2 == pattern.length())
                return pos1 == text.length(); 

            // if next character is not * , then it means either current value at pattern and text should be same or current value at pattern should be . in which case you can skip one character of text

            if (pos2 == pattern.length() - 1 || pattern[pos2+1] != "*") 
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
                    return true
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
};

int main()
{
    RegexMatching rm;

    rm.matchRegexRecursive(string("Tushar"), string("Tushar*a*b*"));


    return 0;
}
