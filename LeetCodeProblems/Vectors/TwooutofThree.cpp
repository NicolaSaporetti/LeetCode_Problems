#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int,int> m;
        vector<int> result;
        sort(begin(nums1),end(nums1));
        sort(begin(nums2),end(nums2));
        sort(begin(nums3),end(nums3));
        nums1.erase(unique(begin(nums1),end(nums1)),end(nums1));
        nums2.erase(unique(begin(nums2),end(nums2)),end(nums2));
        nums3.erase(unique(begin(nums3),end(nums3)),end(nums3));
        for(auto& e : nums1) m[e]++;
        for(auto& e : nums2) m[e]++;
        for(auto& e : nums3) m[e]++;
        for(auto& [key,num] : m) if(num>=2) result.push_back(key);
        return result;
    }
};