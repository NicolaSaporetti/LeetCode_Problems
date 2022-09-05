using namespace std;

class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        for(int i=2;i<=n-2;i++)
        {
            string s;
            int temp = n;
            while(temp>0)
            {
                s.push_back(temp%i+'0');
                temp/=i;
            }
            if(!isPalindrome(s)) return false;
        }
        return true;
    }
    
private:
    bool isPalindrome(string& s)
    {
        for(int i=0;i<s.size()/2;i++)
        {
            if(s[i]!=s[s.size()-1-i]) return false;
        }
        return true;
    }
};