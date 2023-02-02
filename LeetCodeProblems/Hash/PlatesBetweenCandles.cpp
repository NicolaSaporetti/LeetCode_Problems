#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        sz = s.size();
        vector<int> v(sz,0);
        vector<int> res;
        set<int> blocks;
        int plates = 0;
        int start = findStart(s,0,sz);
        if(start<sz) blocks.insert(start);
        for(int i=start+1;i<sz;i++)
        {
            if(s[i]=='|')
            {
                v[i]=plates;
                blocks.insert(i);
            }
            else plates++;
        }
        if(blocks.size()<2) for(auto& q : queries) res.push_back(0);
        else
        {
            for(auto& q : queries)
            {
                auto it = blocks.lower_bound(q[0]);
                auto it2 = blocks.lower_bound(q[1]);
                if(it2==blocks.end() || *it2>q[1]) it2 = prev(it2);
                if(it==blocks.end() || *it>=q[1] || it==it2) res.push_back(0);
                else res.push_back(v[*it2]-v[*it]);
            }
        }
        return res;
    }
private:
    int findStart(string& s, int start, int limit)
    {
        while(start<=limit && s[start]!='|') start++;
        return start;
    }
    int sz;
};