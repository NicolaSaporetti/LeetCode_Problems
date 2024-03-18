#include <vector>
using namespace std;

class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        for(auto& e : changeIndices) e--;
        n = nums.size();
        m = changeIndices.size();
        sum = 0;
        for(int i=0;i<n;i++) sum+=(long long)(nums[i]);
        int minv = n;
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
    bool compute(int mid, vector<int>& nums, vector<int>& changeIndices)
    {
        long long tot = sum;
        priority_queue<int,vector<int>,greater<int> > pq;
        vector<bool> prioTaskSet(n,false);
        vector<bool> isPriorityTask(mid,false);
        for(int i=0;i<mid;i++)
        {
            if(nums[changeIndices[i]]>0 && !prioTaskSet[changeIndices[i]])
            {
                isPriorityTask[i]=true;
                prioTaskSet[changeIndices[i]]=true;
            }
        }
        long long spare = 0;
        int taskLeft = n;
        for(int i=mid-1;i>=0;i--)
        {
            if(isPriorityTask[i])
            {
                pq.push(nums[changeIndices[i]]);
                spare--;
                tot -= nums[changeIndices[i]];
                taskLeft--;
                if(spare<0)
                {
                    spare+=2;
                    tot += pq.top();
                    pq.pop();
                    taskLeft++;
                }
            }
            else
            {
                spare++;
            }
        }
        return (spare>=tot+taskLeft);
    }
    
    int n;
    int m;
    long long sum;
};