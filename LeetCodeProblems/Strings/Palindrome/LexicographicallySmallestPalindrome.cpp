using namespace std;

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int pos = 0;
        int sz = s.size();
        for(int i=0;i<sz/2;i++)
        {
            if(s[i]!=s[sz-1-i])
            {
                if(s[i]>s[sz-1-i]) s[i]=s[sz-i-1];
                else s[sz-i-1]=s[i];
            }
        }
        return s;
    }
};