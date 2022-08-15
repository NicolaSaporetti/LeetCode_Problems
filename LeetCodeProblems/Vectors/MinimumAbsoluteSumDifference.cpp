#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    map<int,vector<int>> myM;
    int sz;
    long long result;
    
    void updateMap(vector<int>& nums1, vector<int>& nums2)
    {
        for(int i=0;i<sz;i++)
        {
            int diff = abs(nums1[i]-nums2[i]);
            auto it = myM.find(diff);
            if(it!=myM.end())
            {
                it->second.push_back(i);
            }
            else
            {
                vector<int> temp(1,i);
                myM.insert(make_pair(diff,temp));
            }
            result+=diff;
            result%=1000000007;
        }
    }
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        sz = nums1.size();
        result = 0;
        updateMap(nums1, nums2);
        vector<int> increasing_vec = nums1;
        sort(increasing_vec.begin(),increasing_vec.end());
        int distReduced = 0;
        for(auto it = myM.rbegin();it!=myM.rend();it++)
        {
            for(int i=0;i<it->second.size();i++)
            {
                int index = it->second[i];
                if(distReduced>=abs(nums1[index]-nums2[index]))
                {
                    return (result-distReduced+1000000007)%1000000007;
                }
                int lower = lower_bound(increasing_vec.begin(),increasing_vec.end(),nums2[index])-increasing_vec.begin();
                int upper = upper_bound(increasing_vec.begin(),increasing_vec.end(),nums2[index])-increasing_vec.begin();
                if(upper<sz) distReduced = max(it->first - abs(increasing_vec[upper]-nums2[index]),distReduced);
                if(lower-1>=0) distReduced = max(it->first - abs(increasing_vec[lower-1]-nums2[index]),distReduced);
                if(lower<sz) distReduced = max(it->first - abs(increasing_vec[lower]-nums2[index]),distReduced);
            }
        }
        return (result-distReduced+1000000007)%1000000007;
    }
};