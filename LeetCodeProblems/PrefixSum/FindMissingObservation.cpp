#include <vector>
using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int res = accumulate(begin(rolls),end(rolls),0);
        vector<int> result;
        int left = mean*(n+rolls.size())-res;
        for(int i=0;i<n;i++)
        {
            int val = left/(n-i);
            if(val<=0 || val>6) return {};
            result.push_back(val);
            left-=val;
        }
        return result;
    }
};