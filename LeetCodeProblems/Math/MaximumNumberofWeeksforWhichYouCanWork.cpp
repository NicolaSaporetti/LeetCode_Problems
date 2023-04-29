#include <vector>
using namespace std;

class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long sum = 0;
        long long res = 0;
        for(auto& e : milestones) sum+=(long long)e;
        res = sum;
        for(auto& e : milestones)
        {
            if(e>sum-e+1) res = min(res, (sum-e)*2+1);
        }
        return res;
    }
};