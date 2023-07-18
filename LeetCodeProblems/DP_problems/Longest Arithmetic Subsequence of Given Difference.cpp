#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        sz = arr.size();
        for(int i=0;i<arr.size();i++) m[arr[i]].insert(i);
        dp.assign(arr.size(),-1);
        int res = 1;
        for(int i=0;i<arr.size();i++) res = max(res,compute(i,arr,difference));
        return res;
    }
private:
    int compute(int pos, vector<int>& arr, int difference)
    {
        if(pos>=sz)
        {
            return 0;
        }
        else if(dp[pos]!=-1) return dp[pos];
        else
        {
            int newNum = arr[pos]+difference;
            if(m.count(newNum)>0)
            {
                auto it = m[newNum].upper_bound(pos);
                if(it==m[newNum].end()) dp[pos]=1;
                else
                {
                    dp[pos]=1+compute(*it,arr,difference);
                }
            }
            else dp[pos]=1;
            return dp[pos];
        }
    }

    int sz;
    unordered_map<int,set<int>> m;
    vector<int> dp;
};