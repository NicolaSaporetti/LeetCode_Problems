#include <vector>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int sz = s.size();
        int res = 0;
        for(int i=0;i<sz;i++)
        {
            vector<int> m(26,0);
            for(int j=i;j<sz;j++)
            {
                m[s[j]-'a']++;
                int minE =INT_MAX;
                for(auto& e : m) if(e!=0) minE = min(minE,e);
                int maxE = 0;
                for(auto& e : m) if(e!=0) maxE = max(maxE,e);
                res+=(maxE-minE);
            }
        }
        return res;
    }
};