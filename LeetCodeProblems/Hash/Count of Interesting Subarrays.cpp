#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int,long long> m;
        int sz= nums.size();
        vector<int> v(sz+1,0);
        long long res = 0;
        int tot = 0;
        for(int i=0;i<nums.size();i++)
        {
            tot = (tot+((nums[i]%modulo==k)? 1 : 0))%modulo;
            v[i+1]=tot;
        }
        for(int i=sz;i>=0;i--)
        {
            res+=m[(v[i]+k)%modulo];
            m[v[i]]++;
        }
        return res;
    }
};