#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        vector<int> res;
        for(auto& e : nums) m1[e]++;
        for(auto& e : nums)
        {
            m2[e]++;
            m1[e]--;
            if(m1[e]==0) m1.erase(e);
            res.push_back(m2.size()-m1.size());
        }
        return res;
    }
};