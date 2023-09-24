#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        vector<int> v(32,0);
        vector<bool> t(31,0);
        int k=0;
        while(target>0)
        {
            if(target%2==1) t[k]=true;
            target/=2;
            k++;
        }
        for(auto& e : nums)
        {
            for(int i=0;i<=30;i++)
                if((1<<i)==e)
                {
                    v[i]++;
                    break;
                }
        }
        int res = 0;
        for(int i=0;i<=30;i++)
        {
            if(t[i] && v[i])
            {
                t[i]=false;
                v[i]--;
            }
            if(v[i]>0)
            {
                for(int j=0;j<i;j++)
                    if(t[j])
                    {
                        res+=(i-j);
                        v[i]--;
                        for(int y=j;y<i;y++) t[y]=false;
                        break;
                    }
            }
            if(v[i]>=2)
            {
                v[i+1]+=(v[i]/2);
                v[i]%=2;
            }
        }
        for(int i=0;i<=30;i++) if(t[i]) return -1;
        return res;
    }
};