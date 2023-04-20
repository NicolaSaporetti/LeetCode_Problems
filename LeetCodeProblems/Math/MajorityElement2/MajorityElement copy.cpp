#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> res;
        for(auto& e : nums) m[e]++;
        for(auto& [key,freq] : m) if(freq>nums.size()/3) res.push_back(key);
        return res;
    }
};