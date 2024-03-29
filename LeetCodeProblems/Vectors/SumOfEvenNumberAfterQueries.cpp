#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int tot=0;
        for_each(begin(nums),end(nums),[&](int e){tot+=((e%2==0)? e : 0);});
        vector<int> res(queries.size(),0);
        for(int i=0;i<queries.size();i++)
        {
            if(nums[queries[i][1]]%2==0) tot-=nums[queries[i][1]];
            nums[queries[i][1]]+=queries[i][0];
            if(nums[queries[i][1]]%2==0) tot+=nums[queries[i][1]];
            res[i]=tot;
        }
        return res;
    }
};