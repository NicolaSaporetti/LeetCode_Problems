using namespace std;

class Solution {
public:
    bool checkPartitioning(string s) {
        for(int i=0;i<s.size()-2;i++)
        {
            if(isPalindrome(s,0,i))
            {
                for(int j=s.size()-1;j>i+1;j--)
                {
                    if(isPalindrome(s,j,s.size()-1) && isPalindrome(s,i+1,j-1)) return true;
                }
            }
        }
        return false;
    }
private:
    bool isPalindrome(string& s, int st, int e)
    {
        int sz = e-st+1;
        for(int i=0;i<sz/2;i++)
        {
            if(s[st+i]!=s[st+sz-1-i]) return false;
        }
        return true;
    }
};