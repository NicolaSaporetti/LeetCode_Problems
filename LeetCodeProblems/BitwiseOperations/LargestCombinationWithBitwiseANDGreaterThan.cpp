#include <vector>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> b(31,0);
        for(int i=0;i<candidates.size();i++)
        {
            int j=0;
            while(candidates[i]>0)
            {
                b[j++]+=candidates[i]%2;
                candidates[i]/=2;
            }
        }
        return *max_element(b.begin(),b.end());
    }
};