#include <vector>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& nums) {
        n = nums;
        sz = nums.size();
        dp.assign(pow(2,sz),-1);
        compute(1,0,0);
        return res;
    }
    
private:
    void compute(int pos,int cur, int identi)
    {
        if(pos>sz/2) res = max(res,cur);
        else
        {
            int v1 = -1;
            int v2 = -1;
            int newV = 0;
            for(int i=0;i<sz;i++)
            {
                if(n[i]==-1) continue;
                swap(v1,n[i]);
                identi|=(1<<i);
                for(int j=i+1;j<sz;j++)
                {
                    if(n[j]==-1) continue;
                    swap(v2,n[j]);
                    identi|=(1<<j);
                    newV = cur+__gcd(v1,v2)*pos;
                    if(dp[identi]<newV)
                    {
                        dp[identi] = newV;
                        compute(pos+1,newV,identi);
                    }
                    identi&=~(1<<j);
                    swap(v2,n[j]);
                }
                identi&=~(1<<i);
                swap(v1,n[i]);
            }
        }
    }
    
    int res;
    int sz;
    vector<int> n;
    vector<int> dp;
};