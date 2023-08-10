#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int,vector<int>> freq;
        vector<int> res;
        for(auto& e : adjacentPairs)
        {
            freq[e[0]].push_back(e[1]);
            freq[e[1]].push_back(e[0]);
        }
        int next = 0;
        for(auto& [k,v] : freq)
            if(v.size()==1)
            {
                res.push_back(k);
                next = v[0];
                break;
            }
        while(res.size()<adjacentPairs.size()+1)
        {
            int prev = res.back();
            res.push_back(next);
            for(int i=0;i<freq[next].size();i++)
            {
                if(freq[next][i]!=prev)
                {
                    next = freq[next][i];
                    break;
                }
            }
        }
        return res;
    }
};