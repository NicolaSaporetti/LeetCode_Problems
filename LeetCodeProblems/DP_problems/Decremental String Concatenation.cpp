#include <vector>
using namespace std;

class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        sz = words.size();
        dp.assign(sz,vector<vector<int>>(26,vector<int>(26,-1)));
        int res = 0;
        for(auto& e : words) res+=e.size();
        int removal = recurse(1,words,words[0][0],words[0].back());
        return res-removal;
    }
private:
    int recurse(int w, vector<string>& words, char c1, char c2)
    {
        if(w>=sz) return 0;
        else if(dp[w][c1-'a'][c2-'a']!=-1) return dp[w][c1-'a'][c2-'a'];
        else
        {
            int rem1 = recurse(w+1,words, words[w][0], c2) + ((c1==words[w].back()) ? 1 : 0);
            int rem2 = recurse(w+1,words, c1, words[w].back()) + ((c2==words[w][0])? 1 : 0);
            dp[w][c1-'a'][c2-'a']= max(rem1,rem2);
            return dp[w][c1-'a'][c2-'a'];
        }
    }
    int sz;
    vector<vector<vector<int>>> dp;
};