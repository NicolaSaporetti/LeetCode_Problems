#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int sz = candiesCount.size();
        vector<bool> res;
        vector<long long> v(sz,0);
        v[0] = candiesCount[0];
        for(int i=1;i<sz;i++) v[i]=v[i-1]+(long long)candiesCount[i];
        for(auto& q : queries)
        {
            long long start = v[q[0]]-(long long)candiesCount[q[0]]+(long long)1;
            long long end = v[q[0]];
            long long consumed = (long long)q[2]*(long long)(q[1]+1);
            if(end<q[1]+1 || start>consumed) res.push_back(false);
            else res.push_back(true);
        }
        return res;
    }
};