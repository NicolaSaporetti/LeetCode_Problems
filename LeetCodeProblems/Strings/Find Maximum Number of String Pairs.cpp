#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        map<string,int> m;
        int res = 0;
        for(auto& word : words) m[word]++;
        for(auto it = m.begin();it!=m.end();m.erase(it++))
        {
            string rev = it->first;
            reverse(begin(rev),end(rev));
            if(m.count(rev)>0)
            {
                if(it->first!=rev)
                {
                    int pairs = min(m[rev],it->second);
                    res+=pairs;
                    m[rev]-=pairs;
                    if(!m[rev]) m.erase(rev);
                }
                else res+=it->second/2;
            }
        }
        return res;
    }
};