#include <vector>
using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> in(n);
        for(auto& e : edges) in[e[1]]++;
        vector<int> res;
        for(int i=0;i<n;i++) if(in[i]==0) res.push_back(i);
        if(res.size()!=1) return -1;
        else return res[0];
    }
};