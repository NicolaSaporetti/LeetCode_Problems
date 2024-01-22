#include <vector>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> v(26);
        int r = 0;
        for(auto e : s) v[e-'a']++;
        for(auto e : t) v[e-'a']--;
        for(auto e : v) if(e>0) r+=e;
        return r;
    }
};