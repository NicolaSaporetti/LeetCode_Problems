#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        unordered_set<string> s;
        for(auto e : forbidden) s.insert(e);
        int res = 0;
        int valid = 0;
        for(int i=0;i<word.size();i++)
        {
            for(int j=max(i-10,valid);j<=i;j++)
            {
                string s1 = word.substr(j,i-j+1);
                if(s.find(s1)!=s.end()) valid = j+1;
            }
            res = max(res, i-valid+1);
        }
        return res;
    }
};  