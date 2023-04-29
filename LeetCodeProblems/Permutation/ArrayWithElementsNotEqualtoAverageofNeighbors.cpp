#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector <int> res;
        sort(nums.begin(),nums.end());
        int i=1,ln=nums.size();
        while(i<ln){
            res.push_back(nums[i]);
            res.push_back(nums[i-1]);
            i+=2;
        }
        if(ln!=res.size()) res.push_back(nums[ln-1]);
        return res;
    }
};