#include <vector>
using namespace std;

class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        vector<int> dp(word.size()+1,0);
        for(int i=1;i<word.size();i++)
        {
            if(word[i]==word[i-1] || word[i]==word[i-1]-1 || word[i]==word[i-1]+1) dp[i+1]=1+dp[i-1];
            else dp[i+1]=dp[i];
        }
        return dp.back();
    }
};