#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto e : nums) m[e]++;
        int sz = nums.size();
        int mv = 0;
        for(auto& [k,v] : m) mv = max(mv,v);
        return (mv>sz/2) ? 2*mv-sz : sz%2;
    }
};