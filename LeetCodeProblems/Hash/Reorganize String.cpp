#include <map>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        vector<int> f(26,0);
        for(auto e : s) f[e-'a']++;
        for(auto e : f) if(e>(s.size()+1)/2) return "";
        for(int i=0;i<26;i++) if(f[i]) m[f[i]].insert(i+'a');
        add_elem_and_remove_it_from_map(m.rbegin()->first, *m.rbegin()->second.begin());
        while(!m.empty())
        {
            auto freq_it = m.rbegin();
            auto elem_it = freq_it->second.begin();
            if(*elem_it==res.back())
            {
                if(freq_it->second.size()==1)
                {
                    freq_it++;
                    elem_it=freq_it->second.begin();
                }
                else elem_it++;
            }
            add_elem_and_remove_it_from_map(freq_it->first,*elem_it);
        }
        return res;
    }
private:
    void add_elem_and_remove_it_from_map(int freq, char elem)
    {
        res.push_back(elem);
        if(freq-1>0) m[freq-1].insert(elem);
        m[freq].erase(elem);
        if(m[freq].empty()) m.erase(freq);
    }

    map<int,unordered_set<char>> m;
    string res;
};