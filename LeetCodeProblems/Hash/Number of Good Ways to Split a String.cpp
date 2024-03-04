#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int numSplits(string s) {
        map<char,int> m1;
        map<char,int> m2;
        int r = 0;
        for(auto e : s) m1[e]++;
        for(auto e : s)
        {
            m1[e]--;
            if(m1[e]==0) m1.erase(e);
            m2[e]++;
            r+=(m1.size()==m2.size());
        }
        return r;
    }
};