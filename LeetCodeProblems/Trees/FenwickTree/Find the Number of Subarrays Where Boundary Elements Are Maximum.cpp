#include <vector>
#include <map>
#include "..\DD\FenwickTreeOneBasedIndexing.cpp"
using namespace std;

class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        map<int,vector<int>> m;
        int sz = nums.size();
        for(int i=0;i<sz;i++) m[nums[i]].push_back(i);
        long long res = 0;
        FenwickTree ft(sz-1);
        long long r = 0;
        int prev = 0;
        for(auto [k,v] : m)
        {
            long long l = 1;
            ft.add(v[0],1);
            prev=v[0];
            r+=l;
            for(int i=1;i<v.size();i++)
            {
                ft.add(v[i],1);
                if(ft.sum(prev,v[i])==v[i]-prev+1)
                {
                    l++;
                }
                else
                {
                    l=1;
                    prev = v[i];
                }
                r+=l;
            }
        }
        return r;
    }
};