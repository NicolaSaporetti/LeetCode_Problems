#include <vector>
using namespace std;

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        sz = words[0].size();
        mod = 1e9+7;
        freq.assign(sz,vector<int>(26,0));
        for(int i=0;i<words.size();i++)
            for(int j=0;j<sz;j++) freq[j][words[i][j]-'a']++;
        dp.assign(sz,vector<vector<int>>(target.size(),vector<int>(26,-1)));
        int res = compute(0,target,0);
        return res;
    }
private:
    long long compute(long long pos, string& target,long long realP)
    {
        if(pos>=target.size()) return 1;
        else if(realP>=sz) return 0;
        else if(dp[realP][pos][target[pos]-'a']!=-1) return dp[realP][pos][target[pos]-'a'];
        else
        {
            long long tot = freq[realP][target[pos]-'a']*compute(pos+1,target,realP+1) + compute(pos,target,realP+1);
            return dp[realP][pos][target[pos]-'a'] = tot%mod;
        }
    }
    
    vector<vector<vector<int>>> dp;
    vector<vector<int>> freq;
    int sz;
    int mod;
};