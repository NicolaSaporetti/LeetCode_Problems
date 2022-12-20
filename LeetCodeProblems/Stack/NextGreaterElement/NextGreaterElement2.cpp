#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> result(nums.size(),-1);
        for(int i=0;i<nums.size();i++)
        {
            while(!s.empty() && nums[s.top()]<nums[i])
            {
                result[s.top()]=nums[i];
                s.pop();
            }
            s.push(i);
        }
        for(int i=0;i<nums.size();i++)
        {
            while(!s.empty() && nums[s.top()]<nums[i])
            {
                result[s.top()]=nums[i];
                s.pop();
            }
        }
        return result;
    }
};