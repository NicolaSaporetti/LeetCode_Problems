#include <vector>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int score =0;
        int sz = tokens.size();
        for(int i=0;i<sz;)
        {
            if(power>=tokens[i])
            {
                score++;
                power-=tokens[i++];
            }
            else if(i==sz-1 || score==0) break;
            else
            {
                score--;
                power+=tokens[--sz];
            }
        }
        return score;
    }
};