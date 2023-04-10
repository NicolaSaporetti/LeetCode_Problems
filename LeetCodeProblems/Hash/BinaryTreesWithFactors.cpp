#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        map<int,long long> m;
        int mod = 1000000007;
        int result = 0;
        for(auto& elem : arr) m[elem]=1;
        for(auto& [key, numberCombination] : m)
        {
            for(auto& [keySub, numberCombinationSubEl] : m)
            {
                if(keySub>=key) break;
                else
                {
                    auto it = m.find(key/keySub);
                    if(key%keySub==0 && it!=m.end()) m[key]+=(it->second*numberCombinationSubEl);
                }
            }
            result=(result+numberCombination%mod)%mod;
        }
        return result;
    }
};