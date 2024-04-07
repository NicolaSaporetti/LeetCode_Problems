#include <vector>
using namespace std;

class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        sort(usageLimits.begin(), usageLimits.end());
        long long total = 0;
        long long count = 0;
        for (int i = 0; i < usageLimits.size(); ++i) {
            total += usageLimits[i];
            if (total >= ((count+1)*(count+2))/2) {
                ++count;
            }
        }
                
        return count;
    }
};