using namespace std;

class Solution {
public:
    int minimumPartition(string s, int k) {
        long long cur = s[0]-'0';
        int res = 1;
        int start = 0;
        for(int i=1;i<s.size();i++)
        {
            if(cur>k) return -1;
            else
            {
                long long newVal = cur*10+(long long)(s[i]-'0');
                if(newVal>k)
                {
                    res++;
                    start = i;
                    cur = s[i]-'0';
                }
                else cur=newVal;
            }
        }
        if(cur>k) return -1;
        return res;
    }
};