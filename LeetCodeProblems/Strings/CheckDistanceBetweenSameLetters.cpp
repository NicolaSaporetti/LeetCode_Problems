#include <vector>
using namespace std;

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> m(26,-1);
        for(int i=0;i<s.size();i++)
        {
            int pos = s[i]-'a';
            if(m[pos]==-1) m[pos] = i;
            else if(m[pos]+distance[pos]+1!=i) return false;
        }
        return true;
    }
};