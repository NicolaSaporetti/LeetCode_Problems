#include <vector>
using namespace std;

class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        n = nums.size();
        m = changeIndices.size();
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i]+1;
            if(sum>m) return -1;
        }
        int minv = sum;
        int maxv = m;
        int res = -1;
        while(minv<=maxv)
        {
            int avg = (minv+maxv)/2;
            if(compute(avg,nums,changeIndices))
            {
                res = avg;
                maxv = avg-1;
            }
            else minv = avg+1;
        }
        return res;
    }
private:
    bool compute(int time, vector<int>& nums, vector<int>& changeIndices)
    {
        vector<int> v(n,-1);
        vector<int> prio(time,-1);
        for(int i=0;i<time;i++) v[changeIndices[i]-1]=i;
        for(int i=0;i<n;i++)
        {
            if(v[i]==-1) return false;
            else prio[v[i]]=i;
        }
        int op = 0;
        for(auto e : prio)
        {
            if(e==-1) op++;
            else
            {
                if(nums[e]>op) return false;
                else op-=nums[e];
            }
        }
        return true;
    }
    
    int n;
    int m;
};