#include <vector>
#include <map>
using namespace std;

class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        map<int,vector<int>> m;
        int sz = times.size();
        vector<int> personVotes(sz,0);
        for(int i=0;i<sz;i++)
        {
            personVotes[persons[i]]++;
            m[personVotes[persons[i]]].push_back(persons[i]);
            winnerAtTimes[times[i]]=m.rbegin()->second.back();
        }
    }
    
    int q(int t) {
        return prev(winnerAtTimes.upper_bound(t))->second;
    }

    map<int,int> winnerAtTimes;
};