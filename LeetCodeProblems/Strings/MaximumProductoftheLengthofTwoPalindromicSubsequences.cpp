using namespace std;

class Solution {
public:
    int maxProduct(string s) {
        int sz = s.size();
        int res = 0;
        for(int i=1;i<pow(2,sz);i++)
        {
            string s1;
            string s2;
            for(int j=0;j<sz;j++)
            {
                if((1<<j)&i) s1+=s[j];
                else s2+=s[j];
            }
            res = max(res, computeMax(s1)*computeMax(s2));
        }
        return res;
    }

private:
    int computeMax(string& s)
    {
        int res = 0;
        int szt = s.size();
        for(int i=1;i<pow(2,szt);i++)
        {
            string temp;
            for(int j=0;j<szt;j++)
            {
                if((1<<j)&i) temp+=s[j];
            }
            if(isPalindrome(temp)) res=max(res,(int)(temp.size()));
        }
        return res;
    }
    
    bool isPalindrome(string& s)
    {
        int sz = s.size();
        for(int i=0;i<sz/2;i++)
        {
            if(s[i]!=s[sz-1-i]) return false;
        }
        return true;
    }
};