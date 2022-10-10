#include <vector>
using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int tot = 0;
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        for(int i=0, j=0;i<players.size() && j<trainers.size(); )
        {
            if(players[i]<=trainers[j])
            {
                tot++;
                i++;
                j++;
            }
            else j++;
        }
        return tot;
    }
};