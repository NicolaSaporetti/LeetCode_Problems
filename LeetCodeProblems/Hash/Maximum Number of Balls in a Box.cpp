#include <map>
using namespace std;

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int res = 0;
        map<int,int> freq;
        for(int i=lowLimit;i<=highLimit;i++)
        {
            int v = i;
            int t =0;
            while(v>0)
            {
                t+=v%10;
                v/=10;
            }
            freq[t]++;
        }
        for(auto& [k,v]: freq) res = max(res,v);
        return res;
    }
};