#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        while(nums.size()>1)
        {
            for(int j=0;j<nums.size();j++) cout<<nums[j]<<" ";
            cout<<endl;
            for(int j=0;j<nums.size()/2;j+=2)
            {
                nums[j]=min(nums[2*j],nums[2*j+1]);
                if(nums.size()!=2) nums[j+1]=max(nums[2*(j+1)],nums[2*(j+1)+1]);
            }
            nums.resize(nums.size()/2);
        }
        return nums[0];
    }
};