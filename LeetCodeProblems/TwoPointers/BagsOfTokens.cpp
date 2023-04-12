#include <vector>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int score = 0;
        int result = 0;
        int end_idx = tokens.size();
        for(int i=0;i<end_idx;)
        {
            if(power>=tokens[i])
            {
                score++;
                power-=tokens[i++];
            }
            else
            {
                if(score==0) break;
                else
                {
                    score--;
                    power+=tokens[--end_idx];
                }
            }
            result = max(result,score);
        }
        return result;
    }
};