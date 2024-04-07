#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<vector<int>>& p) {
    int n = p.size();
    set<pair<int,int>> s, d;
    for (int i = 0; i < n; i++) {
        int x = p[i][0] + p[i][1];
        int y = p[i][0] - p[i][1];
        
        s.insert({x, i}); 
        d.insert({y, i});
    }
    
    int ans = INT_MAX;
    for(int i = 0; i < n; i++) {
        int x = p[i][0] + p[i][1];
        int y = p[i][0] - p[i][1];
        
        s.erase({x, i}); 
        d.erase({y, i}); 
        
        auto [a, is] = *s.begin(); 
        auto [b, ie] = *s.rbegin();
        
        auto [c, isd] = *d.begin(); 
        auto [v, ied] = *d.rbegin();
        
        int dis = max(b - a, v - c); 
        
        ans = min(ans, dis); 
        
        s.insert({x, i}); 
        d.insert({y, i}); 
    }
     
    return ans; 
        
    }
};