#include "TrieBitwise.cpp"
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res(queries.size());
        sort(begin(nums),end(nums));
        vector<vector<int>> q;
        for(int i=0;i<queries.size();i++) q.push_back({queries[i][0],queries[i][1],i});
        sort(begin(q),end(q),[](vector<int>& a, vector<int>& b){return a[1]<b[1];});
        int pos = 0;
        Trie* t = new Trie();
        for(auto& e : q)
        {
            while(pos<nums.size() && nums[pos]<=e[1]) t->insert(nums[pos++]);
            res[e[2]]=t->search(e[0]);
        }
        return res;
    }
};