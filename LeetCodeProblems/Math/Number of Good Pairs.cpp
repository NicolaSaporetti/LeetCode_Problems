#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> m;
        int res = 0;
        for(auto e : nums) m[e]++;
        for(auto& [k,v] : m) res+=v*(v-1)/2;
        return res;
    }
};