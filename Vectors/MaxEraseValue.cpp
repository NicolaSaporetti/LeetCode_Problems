#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int sum;
    int maxN;
    int start;
    map<int,int> myM;
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        sum = 0;
        start = 0;
        for(int i=0;i<nums.size();i++)
        {
            auto it = myM.find(nums[i]);
            if(it!=myM.end())
            {
                maxN = max(maxN, sum);
                int elem = it->second;
                for(int j=start;j<=elem;j++)
                {
                    myM.erase(nums[j]);
                    sum-=nums[j];
                }
                start = elem+1;
            }
            myM.insert(make_pair(nums[i],i));
            sum+=nums[i];
        }
        return max(maxN, sum);
    }
};