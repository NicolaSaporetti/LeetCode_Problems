#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        for(auto it=numbers.begin();it!=numbers.end();it=lower_bound(it,numbers.end(),*it+1))
        {
            auto it2 = find(it+1, numbers.end(),target-*it);
            if(it2!=numbers.end())
            {
                result.push_back(it-numbers.begin()+1);
                result.push_back(it2-numbers.begin()+1);
                break; 
            }
        }
        return result;
    }
};