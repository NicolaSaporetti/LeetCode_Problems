#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int res = 0;
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        int gcd = numsDivide[0];
        for(int i=1;i<numsDivide.size();i++)
        {
            gcd = __gcd(gcd, numsDivide[i]);
        }
        for(auto it = m.begin();it!=m.end();it++)
        {
            if(gcd%it->first==0) return res;
            else if (it->first>gcd) return -1;
            res+=it->second;
        }
        return -1;
    }
};