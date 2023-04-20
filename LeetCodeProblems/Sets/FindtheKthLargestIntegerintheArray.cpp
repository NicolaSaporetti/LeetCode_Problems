#include <vector>
#include <map>
#include <multiset>
using namespace std;

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        map<int,multiset<string>> m;
        for(auto& e : nums) m[e.size()].insert(e);
        int i=nums.size()-k;
        for(auto& [key,vals] : m)
        {
            for(auto& el : vals)
            {
                if(i==0) return el;
                i--;
            }
        }
        return "";
    }
};