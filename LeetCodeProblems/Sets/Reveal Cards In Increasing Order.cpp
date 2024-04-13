#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        set<int> s;
        int pos = 0;
        sort(begin(deck),end(deck));
        for(int i=0;i<deck.size();i++) s.insert(i);
        vector<int> r(deck.size());
        auto it = s.begin();
        while(s.size()>1)
        {
            r[*it]=deck[pos++];
            s.erase(it++);
            if(it==s.end()) it = s.begin();
            it++;
            if(it==s.end()) it = s.begin();
        }
        r[*it]=deck[pos++];
        return r;
    }
};