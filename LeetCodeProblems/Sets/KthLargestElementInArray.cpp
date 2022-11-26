#include <multiset>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> ms;
        for(auto e : nums) ms.insert(e);
        auto it = ms.rbegin();
        for(int i=0;i<k-1;i++) it++;
        return *it;
    }
};