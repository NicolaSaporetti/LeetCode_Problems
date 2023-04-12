#include <vector>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int sz = values.size();
        vector<int> v(sz+2,0);
        int result = 0;
        for(int i=0;i<sz;i++)
        {
            v[i+1] = max(v[i]-1,values[i]);
            result = max(result, v[i]+values[i]-1);
        }
        return result;
    }
};