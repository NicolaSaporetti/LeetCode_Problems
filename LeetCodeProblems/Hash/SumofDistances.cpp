#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,vector<long long>> m;
        long long sz = nums.size();
        vector<long long> result(sz,0);
        unordered_map<long long,long long> order;
        for(int i=0;i<sz;i++)
        {
            if(m.count(nums[i])==0) m[nums[i]].push_back(i);
            else m[nums[i]].push_back(m[nums[i]].back()+(long long)(i));
        }
        for(long long i=0;i<sz;i++)
        {
            if(m[nums[i]].size()==1) result[i]=0;
            else
            {
                long long pos = order[nums[i]];
                long long totToSub = i*(m[nums[i]].size()-pos-1);
                long long totToAdd = i*(pos+1);
                result[i]=totToAdd-m[nums[i]][pos]+(m[nums[i]].back()-m[nums[i]][pos])-totToSub;
                order[nums[i]]++;
            }
        }
        return result;
    }
};