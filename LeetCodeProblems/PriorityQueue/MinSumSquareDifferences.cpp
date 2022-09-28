#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long res = 0;
        sz = nums1.size();
        int k = k1+k2;
        map<int,int> m;
        for(int i=0;i<sz;i++)
        {
            m[abs(nums1[i]-nums2[i])]++;
        }
        while(k>0 && !m.empty())
        {
            int value = m.rbegin()->first;
            int nums = m.rbegin()->second;
            m.erase(value);
            int target = 0;
            if(!m.empty()) target = m.rbegin()->first;
            int maxDist = min(k/nums, value-target);
            value-=maxDist;
            k-=(maxDist*nums);
            if(value!=target)
            {
                if(value-1!=0) m[value-1]+=k;
                m[value]+=nums-k;
                k=0;
            }
            else
            {
                if(value!=0) m[value]+=nums;
            }
        }
        for(auto [f,s] : m)
        {
            res+=(pow(f,2))*s;
        }
        return res;
    }

private:
    int sz;
};