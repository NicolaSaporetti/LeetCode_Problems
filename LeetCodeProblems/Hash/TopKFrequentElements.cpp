#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        map<int, vector<int>> freq;
        vector<int> res(k);
        for(auto e : nums) m[e]++;
        for(auto e : m) freq[e.second].push_back(e.first);
        auto it = freq.rbegin();
        while(k>0)
        {
            for(int i=0;i<it->second.size();i++) res[--k]=it->second[i];
            it++;
        }
        return res;
    }
};