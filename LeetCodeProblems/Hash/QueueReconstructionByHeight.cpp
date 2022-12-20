#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        for(auto& p : people) m[p[0]].push_back({p[1],0});
        for(auto& p : m) sort(p.second.begin(),p.second.end(),greater<pair<int,int>>());
        int sz = people.size();
        for(int i=0;i<sz;i++)
        {
            int el_value = add_result();
            adjust_map(el_value);
        }
        return result;
    }
private:
    int add_result()
    {
        int el_value = 0;
        for(auto it = m.begin();it!=m.end();it++)
        {
            if(it->second.back().first==0)
            {
                el_value=it->first;
                result.push_back({el_value,it->second.back().second});
                it->second.pop_back();
                if(it->second.empty()) m.erase(it);
                break;
            }
        }
        return el_value;
    }

    void adjust_map(int el_value)
    {
        for(auto it = m.begin();it!=m.end() && it->first<=el_value;it++)
        {
            for(int i=0;i<it->second.size();i++)
            {
                it->second[i].first--;
                it->second[i].second++;
            }
        }
    }

    map<int,vector<pair<int,int>>> m;
    vector<vector<int>> result;
};