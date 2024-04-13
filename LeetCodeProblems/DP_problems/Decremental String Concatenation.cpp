#include <vector>
using namespace std;

class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        int len = 0;
        for(auto e : words) len+=e.size();
        dp.assign(26,vector<vector<int>>(26,vector<int>(words.size(),-1)));
        return words[0].size()+dfs(1,words[0][0],words[0].back(),words);
    }
private:
    int dfs(int word, char start, char end, vector<string>& words)
    {
        if(word>=words.size()) return 0;
        else if(dp[start-'a'][end-'a'][word]!=-1) return dp[start-'a'][end-'a'][word];
        else
        {
            int v1 = dfs(word+1,start,words[word].back(),words)-((words[word][0]==end)? 1 : 0);
            int v2 = dfs(word+1,words[word][0],end,words)-((start==words[word].back())? 1 : 0);
            return dp[start-'a'][end-'a'][word]=min(v1,v2)+words[word].size();
        }
    }
    vector<vector<vector<int>>> dp;
};