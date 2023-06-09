#include <vector>
using namespace std;

class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        maxv = *max_element(begin(nums),end(nums));
        vector<vector<int>> occ = fill_occurrencies(nums);
        vector<int> result;
        for(auto& q : queries)
        {
            int lf = q[0];
            vector<int> temp = occ[q[1]+1];
            for(int j=0;j<=maxv;j++) temp[j]-=occ[q[0]][j];
            int pos = 0;
            int res = INT_MAX;
            for(;pos<=maxv;pos++) if(temp[pos]!=0) break;
            for(int i=pos+1;i<=maxv;i++)
            {
                if(temp[i]!=0)
                {
                    res = min(res,i-pos);
                    pos = i;
                }
            }
            res = (res==INT_MAX)? -1 : res;
            result.push_back(res);
        }
        return result;
    }
private:
    vector<vector<int>> fill_occurrencies(vector<int>& nums)
    {
        vector<vector<int>> occ(nums.size()+1,vector<int>(maxv+1,0));
        vector<int> result;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<=maxv;j++)
            {
                occ[i+1][j]=occ[i][j];
            }
            occ[i+1][nums[i]]++;
        }
        return occ;
    }

    int maxv;
};