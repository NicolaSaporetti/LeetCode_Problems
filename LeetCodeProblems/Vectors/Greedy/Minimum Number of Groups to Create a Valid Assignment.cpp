#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto e : nums) m[e]++;
        int minN = INT_MAX;
        for(auto [k,v] : m) minN=min(minN,v);
        for(int i=minN;i>=1;i--)
        {
            bool isCorrect = true;
            int tot = 0;
            for(auto [k,v] : m)
            {
                int g = v/i;
                int r = v%i;
                if(r>g)
                {
                    isCorrect = false;
                    break;
                }
                tot+=(v/(i+1) + bool(v%(i+1)));
            }
            if(isCorrect) return tot;
        }
        return -1;
    }
};