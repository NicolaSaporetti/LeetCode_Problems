#include <vector>
using namespace std;

class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int pos = 0;
        int cor = 0;
        for(int i=0;i<groups.size();i++)
        {
            if(findSub(groups[i],nums,pos)) cor++;
        }
        return (cor==groups.size());
    }
private:
    bool findSub(vector<int>& g, vector<int>& nums, int& pos)
    {
        for(int i=pos;i<=nums.size()-g.size();i++)
        {
            bool cor = true;
            for(int j=0;j<g.size() && cor;j++)
            {
                if(nums[i+j]!=g[j]) cor = false;
            }
            if(cor)
            {
                pos = i+g.size();
                return true;
            }
        }
        pos = nums.size();
        return false;
    }
};