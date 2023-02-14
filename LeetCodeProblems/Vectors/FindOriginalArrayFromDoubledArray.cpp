#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()%2==1) return {};
        vector<int> v;
        map<int,int> m;
        for(auto& e : changed) m[e]++;
        for(auto& [key,val] : m)
        {
            if(!m.count(key*2) || m[key*2]<val) return {};
            else
            {
                if(key==0)
                {
                    if(val%2==1) return {};
                    else for(int i=0;i<val/2;i++) v.push_back(key);
                }
                else
                {
                    for(int i=0;i<val;i++) v.push_back(key);
                    m[key*2]-=val;
                    if(m[key*2]==0) m.erase(key*2);
                }
            }
        }
        return v;
    }
};