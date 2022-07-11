#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int sz = nums.size();
        vector<int> results(sz,0);
        map<int,int> myM;
        results[0] = nums[0];
        myM.insert(make_pair(nums[0],1));
        for(int i=1;i<sz;i++)
        {
            results[i] = nums[i]+myM.rbegin()->first;
            auto it = myM.find(results[i]);
            if(it!=myM.end()) it->second++;
            else
            {
                myM.insert(make_pair(results[i],1));
            }
            if(i-k>=0)
            {
                auto it2 = myM.find(results[i-k]);
                if(it2->second ==1) myM.erase(it2);
                else
                {
                    it2->second--;
                }
            }
        }
        return results[sz-1];
    }
};