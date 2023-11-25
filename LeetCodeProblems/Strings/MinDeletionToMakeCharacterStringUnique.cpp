#include <vector>
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        vector<int> f(26,0);
        for(auto& e : s) f[e-'a']++;
        sort(begin(f),end(f));
        int res = 0;
        for(int i=25;i>=1;i--)
        {
            if(f[i-1]==0) break;
            else if(f[i]==0)
            {
                res+=f[i-1];
                f[i-1]=0;
            }
            else if(f[i]<=f[i-1])
            {
                res+=(f[i-1]-f[i]+1);
                f[i-1]=f[i]-1;
            }
        }
        return res;
    }
};