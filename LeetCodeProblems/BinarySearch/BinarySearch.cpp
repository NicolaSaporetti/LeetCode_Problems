#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index = find(nums.begin(), nums.end(), target) - nums.begin();
        return (index != nums.size())? index : -1;
    }
};