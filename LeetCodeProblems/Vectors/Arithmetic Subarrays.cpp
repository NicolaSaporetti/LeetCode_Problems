#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;
        for(int i=0;i<l.size();i++)
        {
            vector<int> v;
            for(int j=l[i];j<=r[i];j++) v.push_back(nums[j]);
            if(v.size()<=2) res.push_back(true);
            else
            {
                sort(begin(v),end(v));
                int dif = v[1]-v[0];
                bool isOk = true;
                for(int k=2;k<v.size() && isOk;k++)
                    if(v[k]-v[k-1]!=dif) isOk = false;
                res.push_back(isOk);
            }
        }
        return res;
    }
};