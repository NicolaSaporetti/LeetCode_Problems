#include <vector>
using namespace std;

class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int sz = groups.size();
        vector<string> res;
        int maxV = 1;
        int maxE = 0;
        vector<pair<int,int>> dp(sz,{-1,1});
        for(int i=0;i<sz;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(groups[i]!=groups[j] && words[i].size()==words[j].size() && hamming(i,j,words)==1 && dp[i].second<dp[j].second+1)
                {
                    dp[i].second = dp[j].second+1;
                    dp[i].first = j;
                    if(dp[i].second>maxV)
                    {
                        maxV=dp[i].second;
                        maxE = i;
                    }
                }
            }
        }
        res.resize(maxV);
        for(int i=maxV-1;i>=0;i--)
        {
            res[i]=words[maxE];
            if(dp[maxE].first!=-1) maxE = dp[maxE].first;
        }
        return res;
    }
private:
    int hamming(int i, int j, vector<string>& words)
    {
        int d = 0;
        for(int z=0;z<words[i].size();z++)
        {
            if(words[i][z]!=words[j][z]) d++;
        }
        return d;
    }
};