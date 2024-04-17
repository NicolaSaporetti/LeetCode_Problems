#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        n = nums.size();
        m = andValues.size();
        dp.assign(n,vector<unordered_map<int,int>>(m));
        int r = dfs((1<<20)-1,0,0,nums,andValues);
        return (r>=1e9)? -1 : r;
    }
private:
    int dfs(int bw, int pos, int p2, vector<int>& nums, vector<int>& andValues)
    {
        if(pos>=n && p2>=m) return 0;
        else if(p2>=m || (pos>=n && p2<m)) return 1e9;
        else if(dp[pos][p2].count(bw)) return dp[pos][p2][bw];
        else
        {
            int nbw=bw&nums[pos];
            int res = 0;
            int close = 1e9;
            if(nbw<andValues[p2]) return 1e9;
            if(nbw==andValues[p2]) close = nums[pos]+dfs((1<<20)-1,pos+1,p2+1,nums,andValues);
            int keep = dfs(nbw,pos+1,p2,nums,andValues);
            return dp[pos][p2][nbw]=res=min(close,keep);
        }
    }
    
    vector<vector<unordered_map<int,int>>> dp;
    int n;
    int m;
};