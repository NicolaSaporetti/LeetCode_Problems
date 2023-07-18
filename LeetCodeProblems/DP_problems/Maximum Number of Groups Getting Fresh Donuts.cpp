#include <vector>
using namespace std;

class Solution {
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        v.assign(batchSize,0);
        for(auto& e : groups) v[e%batchSize]++;
        sz = batchSize;
        int res = computeFixSize();
        l.assign(accumulate(begin(v),end(v),0),0);
        computeLeft(0,0,0);
        return res+((l.size()>0)? l.back() : 0);
    }
private:
    int computeFixSize()
    {
        int res = 0;
        for(int i=1;i<=(sz-1)/2;i++)
        {
            int n = min(v[i],v[sz-i]);
            v[i]-=n;
            v[sz-i]-=n;
            res+=n;
        }
        res+=v[0];
        v[0]=0;
        if(sz%2==0)
        {
            res+=v[sz/2]/2;
            v[sz/2]%=2;
        }
        return res;
    }
    
    void computeLeft(int pos, int num, int val)
    {
        if(num>=l.size()) return;
        else
        {
            int nval = val+((pos==0)? 1 : 0);
            if(l[num]>nval) return;
            else
            {
                l[num]=nval;
                for(int i=1;i<sz;i++)
                {
                    if(v[i]>0)
                    {
                        v[i]--;
                        computeLeft((pos+i)%sz, num+1, nval);
                        v[i]++;
                    }
                }
            }
        }
    }
    
    int sz;
    vector<int> l;
    vector<int> v;
};