#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        long long res = 0;
        int mod = 1e9+7;
        unordered_map<int,long long> m;
        for(auto& e : deliciousness) m[e]++;
        vector<int> p2(30,1);
        for(int i=1;i<30;i++) p2[i]=2*p2[i-1];
        for(auto it = m.begin();it!=m.end();it++)
        {
            for(int i=0;i<30;i++)
            {
                int miss = p2[i]-it->first;
                if(miss>it->first && m.count(miss)>0)
                {
                    res = (res+it->second*m[miss])%mod;
                }
                else if(miss==it->first) res = (res+(it->second*(it->second-1))/2)%mod;
            }
        }
        return res;
    }
};