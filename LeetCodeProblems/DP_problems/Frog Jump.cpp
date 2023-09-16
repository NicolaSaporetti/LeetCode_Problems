#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        sz = stones.size();
        for(int i=0;i<sz;i++) stoneP[stones[i]]=i;
        dp.assign(sz+1,vector<int>(sz+1,-1));
        return compute(1,1);
    }
private:
    bool compute(int speed, int loc)
    {
        if(speed == 0 || stoneP.count(loc)<=0) return false;
        else if(loc==stoneP.rbegin()->first) return true;
        else if(dp[stoneP[loc]][speed]!=-1) return dp[stoneP[loc]][speed];
        else return dp[stoneP[loc]][speed]= compute(speed+1,loc+speed+1) || compute(speed,loc+speed) || compute(speed-1,loc+speed-1);
    }
    
    map<int,int> stoneP;
    vector<vector<int>> dp;
    int sz;
};