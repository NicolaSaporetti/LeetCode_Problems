#include <unordered_map>
using namespace std;

class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string,int> m;
        string s;
        for(int i=0;i<word.size();i++)
        {
            s+=word[i];
            if(s.size()==k)
            {
                m[s]++;
                s.clear();
            }
        }
        int mv = 0;
        for(auto [k,v] : m) mv=max(v,mv);
        return word.size()/k-mv;
    }
};