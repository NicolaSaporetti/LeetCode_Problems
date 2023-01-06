#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        map<string,int> stringCount;
        map<int,vector<string>> stringByCount;
        for(auto& w : words) stringCount[w]++;
        for(auto& w : stringCount) stringByCount[w.second].push_back(w.first);
        for(auto i=stringByCount.rbegin();i!=stringByCount.rend() && k>0;i++)
        {
            for(int j=0;j<i->second.size() && k>0;j++)
            {
                res.push_back(i->second[j]);
                k--;
            }
        }
        return res;
    }
};