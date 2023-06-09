#include <vector>
using namespace std;

class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        sort(begin(packages),end(packages));
        for(auto& b : boxes) sort(begin(b),end(b));
        int sz = packages.size();
        long long mod = 1e9+7;
        vector<long long> cum(sz+1,0);
        for(int i=0;i<sz;i++) cum[i+1]=cum[i]+(long long)packages[i];
        long long res = 1000000000000;
        for(int i=0;i<boxes.size();i++)
        {
            if(boxes[i].back()<packages.back()) continue;
            long long waste = 0;
            long long prev = -1;
            for(int j=0;j<boxes[i].size();j++)
            {
                auto it = upper_bound(begin(packages),end(packages),boxes[i][j]);
                if(it==begin(packages)) continue;
                else
                {
                    long long pos = (it-packages.begin())-1;
                    long long tot = cum[pos+1]-cum[prev+1];
                    waste+=((long long)boxes[i][j]*(pos-prev)-tot);
                    prev = pos;
                }
            }
            res = min(res,waste);
        }
        return (res==1000000000000)?-1: res%mod;
    }
};