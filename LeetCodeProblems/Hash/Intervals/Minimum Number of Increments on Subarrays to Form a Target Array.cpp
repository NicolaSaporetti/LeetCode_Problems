#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        vector<int> t;
        t.push_back(0);
        for(auto e : target) t.push_back(e);
        t.push_back(0);
        map<int,vector<int>> m;
        int sz = target.size();
        set<int> s;
        s.insert(sz+1);
        s.insert(0);
        for(int i=0;i<sz;i++)
        {
            m[t[i+1]].push_back(i+1);
        }
        int r = 0;
        for(auto [k,v] : m)
        {
            int last = -1;
            int first = -1;
            for(auto e : v)
            {
                int next = *s.upper_bound(e);
                int prevv = *prev(s.lower_bound(e));
                if(last!=next)
                {
                    r+=t[e]-max(t[next],t[prevv]);
                    last = next;
                    first= prevv;
                }
                s.insert(e);
            }
        }
        cout<<endl;
        return r;
    }
};