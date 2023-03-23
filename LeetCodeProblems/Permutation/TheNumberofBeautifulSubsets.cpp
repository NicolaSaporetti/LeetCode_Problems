#include <vector>
using namespace std;

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        res = 0;
        sz = nums.size();
        m.assign(sz,vector<bool>(sz,false));
        for(int i=0;i<sz;i++)
        {
            for(int j=i+1;j<sz;j++)
            {
                if(abs(nums[i]-nums[j])==k)
                {
                    m[i][j]=true;
                    m[j][i]=true;
                }
            }
        }
        traverse(0);
        return res;
    }
private:
    void traverse(int start)
    {
        for(int i=start;i<sz;i++)
        {
            bool isForbidden = false;
            for(int j=0;j<v.size();j++)
            {
                if(m[v[j]][i])
                {
                    isForbidden=true;
                    break;
                }
            }
            if(!isForbidden)
            {
                res++;
                v.push_back(i);
                traverse(i+1);
                v.pop_back();
            }
        }
    }
    
    int res;
    vector<int> v;
    int sz;
    vector<vector<bool>> m;
};