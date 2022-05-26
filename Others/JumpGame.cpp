#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
private:
    bool jump(vector<int>& nums, int index)
    {
        //cout<<"Jump to: "<<index<<endl;
        bool result = false;
        if(!numsVisisted[index])
        {
            numsVisisted[index] = true;
            if(index==nums.size()-1) return true;
            //cout<<nums[index]<<endl;
            for(int i=nums[index];i>=1 && !result;i--)
            {
                if(index+i<nums.size())
                {
                    result = jump(nums,index+i);
                }
            }
        }
        return result;
    }

public:
    bool canJump(vector<int>& nums) {
        numsVisisted.resize(nums.size());
        for(int i=0;i<numsVisisted.size();i++) numsVisisted[i]=false;
        return jump(nums,0);
    }
    vector<bool> numsVisisted;
};

int main()
{
    Solution solution;
    vector<int> vec = {2,3,2,1,0,1};
    cout<<solution.canJump(vec)<<endl;
    return 0;
}