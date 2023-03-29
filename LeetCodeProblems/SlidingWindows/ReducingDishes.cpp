#include <vector>
using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int sz = satisfaction.size();
        int tot = 0;
        int inc = 0;
        for(int i=sz-1;i>=0;i--)
        {
            inc+=satisfaction[i];
            if(inc<0) break;
            tot+=inc;
        }
        return tot;
    }
};