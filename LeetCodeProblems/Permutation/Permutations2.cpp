#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sz = nums.size();
        multiset<int> s;
        for(int i=0;i<nums.size();i++) s.insert(nums[i]);
        populate(s);
        return solutions;
    }

private:
    void populate(multiset<int> s)
    {
        if(temp.size()==sz) solutions.push_back(temp);
        else
        {
            multiset<int> s2 = s;
            int prev = INT_MAX;
            for(auto& e : s)
            {
                if(e!=prev)
                {
                    prev=e;
                    auto it = s2.find(e);
                    s2.erase(it);
                    temp.push_back(e);
                    populate(s2);
                    temp.pop_back();
                    s2.insert(e);
                }
            }
        }
    }

    vector<vector<int>> solutions;
    vector<int> temp;
    int sz;
};