using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int sz = s.size();
        int tot=0;
        auto verifyPalindrome = [&](int index, int index2)
        {
            int tot = 0;
            while(index>=0 && index2<sz)
            {
                if(s[index--]==s[index2++]) tot++;
                else break;
            }
            return tot;
        };
        for(int i=0;i<sz;i++)
        {
            tot+=verifyPalindrome(i,i);
            if(i+1<sz) tot+=verifyPalindrome(i,i+1);
        }
        return tot;
    }
};