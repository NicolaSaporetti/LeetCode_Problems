using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int r = 0;
        int n = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') n++;
            else
            {
                if(i+1>=s.size() || s[i+1]=='(') r++;
                else i++;
                if(n==0)
                {
                    r++;
                    n++;
                }
                n--;
            }
        }
        r+=n*2;
        return r;
    }
};