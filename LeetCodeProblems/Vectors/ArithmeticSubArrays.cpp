#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;
        for(int i=0;i<l.size();i++)
        {
            res.push_back(isArithSeq(l[i],r[i],nums));
        }
        return res;
    }
    
private:
    bool isArithSeq(int l, int r, vector<int>& nums)
    {
        vector<int> temp(r-l+1);
        copy(nums.begin()+l,nums.begin()+r+1,temp.begin());
        sort(temp.begin(),temp.end());
        int progression = temp[1]-temp[0];
        for(int i=2;i<temp.size();i++)
        {
            if(temp[i]-temp[i-1]!=progression) return false;
        }
        return true;
    }
};