#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int sz = digits.size();
        vector<int> res;
        set<int> s;
        for(int i=0;i<sz;i++)
        {
            if(digits[i]==0) continue;
            for(int j=0;j<sz;j++)
            {
                if(j==i) continue;
                for(int z=0;z<sz;z++)
                {
                    if(digits[z]%2==1 || z==i || z==j) continue;
                    s.insert(digits[i]*100+digits[j]*10+digits[z]);
                }
            }
        }
        for(auto& e : s) res.push_back(e);
        return res;
    }
};