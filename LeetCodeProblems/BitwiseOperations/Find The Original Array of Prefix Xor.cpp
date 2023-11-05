#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> res;
        int val = 0;
        for(auto& e : pref)
        {
            res.push_back(val^e);
            val^=res.back();
        }
        return res;
    }
};