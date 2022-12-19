#include <unordered_map>
using namespace std;

class Solution {
public:
    Solution(vector<int>& nums) {
        srand (time(NULL));
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int sz = m[target].size();
        int e = rand()%sz;
        return m[target][e];
        
    }
private:
    unordered_map<int,vector<int>> m;
};