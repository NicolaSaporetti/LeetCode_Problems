#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        map<int,int> m;
        for(auto& e : stones) m[e]++;
        while(m.size()>1 || (m.size()==1 && m.rbegin()->second>1))
        {
            auto it = m.rbegin();
            if(it->second>1)
            {
                it->second-=2;
                if(it->second==0) m.erase(next(it).base());
            }
            else
            {
                int newWeight = it->first-next(it)->first;
                m.erase(next(it++).base());
                it->second--;
                if(it->second==0) m.erase(next(it).base());
                m[newWeight]++;
            }
        }
        return (m.empty())? 0 : m.begin()->first;
    }
};