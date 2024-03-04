#include <vector>
using namespace std;

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        sz = stones.size();
        dp.assign(sz,vector<int>(sz,-1e9));
        st.assign(sz+1,0);
        for(int i=0;i<sz;i++) st[i+1]=st[i]+stones[i];
        return solve(0,0,stones);
    }
private:
    int solve(int pos, int move, vector<int>& stones)
    {
        if(move>=sz-1) return 0;
        else if(dp[pos][move]!=-1e9) return dp[pos][move];
        else
        {
            int last = sz-move+pos;
            int res = 0;
            int sum1 = st[last]-st[pos+1];
            int sum2 = st[last-1]-st[pos];
            res = max(sum1-solve(pos+1,move+1,stones),sum2-solve(pos,move+1,stones));
            return dp[pos][move]=res;
        }
    }
    
    vector<vector<int>> dp;
    vector<int> st;
    int sz;
};