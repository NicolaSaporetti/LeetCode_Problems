#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int,int> m;
        for(auto& e : nums) m[e]++;
        for(auto& [key,v] : m)
        {
            if(k==2*key)
            {
                res+=v/2;
                v%=2;
            }
            else
            {
                if(m.count(k-key)==0) continue;
                int n = m[k-key];
                int mult = min(n,v);
                res+= mult;
                v-=mult;
                m[k-key]-=mult;
            }
        }
        return res;
    }
};