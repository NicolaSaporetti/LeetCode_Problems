#include <vector>
#include <unordered_map>
#include "..\DD\FenwickTreeOneBasedIndexing.cpp"
using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> v = nums;
        sort(begin(v),end(v));
        v.erase(unique(begin(v),end(v)),v.end());
        int p=0;
        unordered_map<int,int> m;
        for(auto& e : v) m[e]=p++;
        for(auto& e : nums) e= m[e];
        FenwickTree ft1(p);
        FenwickTree ft2(p);
        int e1 = 1;
        int e2 = 1;
        vector<int> v1{nums[0]};
        vector<int> v2{nums[1]};
        ft1.add(nums[0],1);
        ft2.add(nums[1],1);
        for(int i=2;i<nums.size();i++)
        {
            int s1 = e1-ft1.sum(nums[i]);
            int s2 = e2-ft2.sum(nums[i]);
            if(s2>s1 || (s2==s1 && e2<e1))
            {
                e2++;
                v2.push_back(nums[i]);
                ft2.add(nums[i],1);
            }
            else
            {
                e1++;
                v1.push_back(nums[i]);
                ft1.add(nums[i],1);
            }
        }
        for(auto e : v2) v1.push_back(e);
        for(auto& e : v1) e=v[e];
        return v1;
    }
};