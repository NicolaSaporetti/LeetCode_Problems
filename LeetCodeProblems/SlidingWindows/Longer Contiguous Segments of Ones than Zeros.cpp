using namespace std;

class Solution {
public:
    bool checkZeroOnes(string s) {
        int tot = 1;
        int one = 0;
        int zero = 0;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]!=s[i-1])
            {
                if(s[i-1]=='0') zero=max(zero,tot);
                else one = max(one,tot);
                tot = 0;
            }
            tot++;
        }
        if(s[s.size()-1]=='0') zero=max(zero,tot);
        else one = max(one,tot);
        return one>zero;
    }
};