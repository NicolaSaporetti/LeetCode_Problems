#include <vector>
using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> v(26,0);
        for(auto e : word) v[e-'a']++;
        sort(begin(v),end(v));
        int tot = INT_MAX;
        int r = 0;
        for(int i=0;i<25;i++)
        {
            int val = r;
            for(int j=i+1;j<26;j++)
            {
                if(v[j]-v[i]>k) val+=max(v[j]-v[i]-k,0);
            }
            tot = min(tot,val);
            r+=v[i];
        }
        tot = min(tot,r);
        return tot;
    }
};