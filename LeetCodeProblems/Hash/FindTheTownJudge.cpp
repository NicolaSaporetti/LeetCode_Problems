#include <vector>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int,int>> v(n);
        for(auto& e : trust)
        {
            v[e[1]-1].second++;
            v[e[0]-1].first++;
        }
        auto it = find_if(begin(v),end(v),[&](auto elem) { return(elem.second==n-1 && elem.first==0); });
        return (it==end(v))? -1 : it-begin(v)+1;

    }
};