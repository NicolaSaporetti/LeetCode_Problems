#include <queue>
using namespace std;

class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int startR = 0;
        queue<int> q;
        int r = 1;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==s[i-1]) q.push(i);
            if(q.size()>1)
            {
                startR = q.front();
                q.pop();
            }
            r = max(r, i-startR+1);
        }
        return r;
    }
};