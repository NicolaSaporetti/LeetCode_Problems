#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1;
        set<int> s2;
        set<int> com;
        int mod = 1e9+7;
        for(auto e : nums1) s1.insert(e);
        for(auto e : nums2) s2.insert(e);
        for(auto e : s1) if(s2.find(e)!=s2.end()) com.insert(e);
        long long v1 = 0;
        long long v2 = 0;
        long long co = 0;
        int i=0;
        int j=0;
        for(auto e : com)
        {
            v1 = 0;
            v2 = 0;
            for(;i<nums1.size();i++)
            {
                v1+=(long long)nums1[i];
                if(nums1[i]==e) break;
            }
            for(;j<nums2.size();j++)
            {
                v2+=(long long)nums2[j];
                if(nums2[j]==e) break;
            }
            i++;
            j++;
            co+=max(v1,v2);
        }
        v1=0;
        v2=0;
        for(;i<nums1.size();i++) v1+=(long long)nums1[i];
        for(;j<nums2.size();j++) v2+=(long long)nums2[j];
        return (co+max(v1,v2))%mod;
        
    }
};