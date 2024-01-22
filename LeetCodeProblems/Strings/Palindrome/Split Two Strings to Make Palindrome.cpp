using namespace std;

class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        sz = a.size();
        if(isPalindrome(a,b)) return true;
        if(isPalindrome(b,a)) return true;
        return false;
    }
    
    bool isPalindrome(string& a, string& b)
    {
        int i=0;
        for(;i<sz/2;i++) if(a[i]!=b[sz-1-i]) break;
        return isPalindrome(a,i) || isPalindrome(b,i);
        return true;
    }
    
    bool isPalindrome(string& a, int s)
    {
        for(int i=0;i<(sz-s*2)/2;i++)
        {
            if(a[i+s]!=a[sz-1-i-s]) return false;
        }
        return true;
    }
    
    int sz;
};