#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        vis.assign(1001,false);
        vis[start]=true;
        q.push(start);
        int num = 0;
        if(start==goal) return num;
        while(!q.empty())
        {
            num++;
            int sz = q.size();
            for(int j=0;j<sz;j++)
            {
                int el = q.front();
                q.pop();
                for(int i=0;i<nums.size();i++)
                {
                    int newEl = el+nums[i];
                    computeNum(newEl);
                    if(newEl==goal) return num;
                    newEl = el-nums[i];
                    computeNum(newEl);
                    if(newEl==goal) return num;
                    newEl = el^nums[i];
                    computeNum(newEl);
                    if(newEl==goal) return num;
                }
            }
        }
        return -1;
    }
    
    void computeNum(int newEl)
    {
        if(newEl>=0 && newEl<=1000 && !vis[newEl])
        {
            vis[newEl]=true;
            q.push(newEl);
        }
    }
    
    queue<int> q;
    vector<bool> vis;
};