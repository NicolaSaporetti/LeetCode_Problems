using namespace std;

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int nz = 0;
        int no = 0;
        int res = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0')
            {
                if(i>0 && s[i-1]=='1')
                {
                    res = max(res,2*min(nz,no));
                    nz = 0;
                    no = 0;
                }
                nz++;
            }
            else
            {
                no++;
            }
        }
        res = max(res,2*min(nz,no));
        return res;
    }
};