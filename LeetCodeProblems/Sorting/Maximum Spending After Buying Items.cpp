#include <vector>
using namespace std;

class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        vector<long long> v;
        long long res = 0;
        for(auto& r : values)
            for(auto& c : r) v.push_back(c);
        sort(begin(v),end(v));
        for(long long i=0;i<v.size();i++) res+=v[i]*(i+1);
        return res;
    }
};