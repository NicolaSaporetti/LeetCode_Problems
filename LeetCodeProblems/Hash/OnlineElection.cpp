#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef pair<int, int> pi;
struct myComp {
    constexpr bool operator()(
        pair<int, int> const& top_pq,
        pair<int, int> const& new_el)
    {
        return (new_el.first>=top_pq.first)? true : false;
    }
};

class TopVotedCandidate {
private:
    vector<int> winnerByTimestamp;
    vector<int> times;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->times = times;
        set<int> myS;
        for(int i=0;i<persons.size();i++)
        {
            myS.insert(persons[i]);
        }
        vector<int> uniqueP(myS.size(),0);
        
        priority_queue<pi,vector<pi>,myComp> pq;
        for(int i=0;i<times.size();i++)
        {
            uniqueP[persons[i]]++;
            pq.push(make_pair(uniqueP[persons[i]],persons[i]));
            winnerByTimestamp.push_back(pq.top().second);
        }
    }
    
    int q(int t) {
        return winnerByTimestamp[--upper_bound(times.begin(),times.end(),t)-times.begin()];
    }
};