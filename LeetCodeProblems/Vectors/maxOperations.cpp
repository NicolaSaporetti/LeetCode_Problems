#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int result =0;
        map<int,int> myMap;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<k)
            {
                auto ret = myMap.insert(pair<int,int>(nums[i],1));
                if(ret.second == false)
                {
                    int number = ret.first->second + 1;
                    myMap.erase(ret.first);
                    myMap.insert(pair<int,int>(nums[i],number));
                }
            }
        }
        for(auto it = myMap.begin();it!=myMap.end();it++)
        {
            if(it->first*2 == k)
            {
                result+=it->second/2;
            }
            else
            {
                auto it2 = myMap.find(k-it->first);
                if(it2!=myMap.end())
                {
                    result+=min(it->second, it2->second);
                    myMap.erase(it2);
                }
            }
        }
        return result;
    }
};