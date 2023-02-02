#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        map<int,int> m;
        int result = 0;
        int sz = difficulty.size();
        for(int i=0;i<sz;i++)
        {
            if(m.count(difficulty[i])==0) m[difficulty[i]]=profit[i];
            else m[difficulty[i]]=max(m[difficulty[i]],profit[i]);
        }
        int basePay = 0;
        for(auto& [difficulty, pay] : m)
        {
            basePay=max(basePay,pay);
            pay=basePay;
        }
        for(auto& skill : worker)
        {
            auto it = m.lower_bound(skill);
            if(it==m.end()) result+=prev(it)->second;
            else if(it->first>skill)
            {
                if(it!=m.begin()) result+=prev(it)->second;
            }
            else result+=it->second;
        }
        return result;
    }
};