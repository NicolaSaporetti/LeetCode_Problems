#include <vector>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int total = 0;
        int indexLast = 0;
        if(nums.size()>=3)
        {
            sort(nums.begin(),nums.end());
            for(int i=0;i<nums.size()-2;i++)
            {
                indexLast = i+2;
                for(int j=i+1;j<nums.size()-1;j++)
                { 
                    if(indexLast == j) indexLast++;
                    while(indexLast<nums.size() && nums[i]+nums[j]>nums[indexLast]) indexLast++;
                    total+=(indexLast-j-1);
                }
            }
        }
        return total;
    }
};