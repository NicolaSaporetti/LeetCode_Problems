using namespace std;

class Solution {
public:
    string smallestString(string s) {
        int sz = s.size();
        int start = sz;
        for(int i=0;i<sz;i++)
        {
            if(s[i]!='a')
            {
                start = i;
                break;
            }
        }
        if(start==sz) s[sz-1]='z';
        else
        {
            for(int i=start;i<sz;i++)
            {
                if(s[i]!='a') s[i]--;
                else break;
            }
        }
        return s;
    }
};