#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        map<int,int> m;
        for(auto e : nums) m[e]++;
        for(auto it = m.rbegin();it!=m.rend();it++)
        {
            if(it->first%m.begin()->first!=0) return 1;
        }
        return (m.begin()->second+1)/2;
    }
};